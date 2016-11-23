#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <string.h>
#include <ctype.h>

void child_process(int, int, int);
int parent_process();
void sig_child_process(int );
void sig_usr1_handler(int ); 
void sig_alarm(int );

pid_t child_pid;
char parent_output[] = "*";

int main(int argc, char *argv[]){
  
  if(argc < 4){
    printf("Usage error\n");
    exit(EXIT_FAILURE);
  }
  
  int a0 = atoi(argv[1]);
  int r = atoi(argv[2]);
  int n = atoi(argv[3]);
  
  if((child_pid = fork()) < 0){
   perror("Fork");
   exit(1);
  }
  else if( child_pid == 0){
    child_process(a0, r, n);
    exit(14);
  }
  else{
    parent_process();
    exit(0);
  }
  return 0;
}

void child_process(int a0, int r, int n){
 	alarm(1);
	int index = 1;
	double ai = (double) a0;
	
	struct sigaction act;
	act.sa_handler = sig_alarm;
	act.sa_flags = 0;

	sigaction(SIGALRM,&act,NULL);
	    
    while(index <= n){
      ai = ai + (double) 1.0 / r;
      index++;
      printf("index %d\n",index);
    }   
    
}

void sig_alarm(int sig){
  
	if (kill(getppid(), SIGUSR1) < 0){
		printf("Error sending SIGUSR1 to parinte\n");
		exit(4);
	}
}

int parent_process(){

	struct sigaction act;
	act.sa_handler = sig_usr1_handler;
	act.sa_flags = 0;

	sigaction(SIGUSR1,&act,NULL);

	struct sigaction act1;
	act1.sa_handler = sig_child_process;
	act1.sa_flags = 0;

	sigaction(SIGCHLD,&act1,NULL);

	while(1){
		fprintf(stdout, "%s",parent_output);
	}
	fprintf(stdout,"\n");
	return 0;
}
void sig_usr1_handler(int sig){
  
  strcpy(parent_output,"+");  
  
}


void sig_child_process(int sig){
  
	int status;
	wait(&status);
	printf("Child ended with code %d\n", WEXITSTATUS(status));
	exit(0);
}