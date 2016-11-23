#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/wait.h>

char pr[] = "merge aici\n";
int pfd[2], pfd2[2], pfd3[2];

void parent_write(){
	char read_parent[100];
	char write_parent[100]="";
	FILE *stream_date;
	stream_date = fopen("date.txt", "r");
		if(stream_date == NULL)
		printf("Doesn't open date.txt\n");
		
		while(fgets(read_parent, sizeof(read_parent), stream_date) != NULL){
			strcat(write_parent, read_parent);

		}

		write(pfd[1], write_parent, sizeof(write_parent));
		fclose(stream_date);	
}

void child_1_ReadAndWrite(){
    
	int i, j = 0;
	char to_child_2[1024] = "", buf[104];
	
	char child_r[1024];
	
	read(pfd[0], buf, sizeof(buf));
			strcpy(child_r,"");
			strcat(child_r, buf);

		for(i = 0; i < strlen(child_r); i++){
			if(child_r[i] >= 'a' && child_r[i] <= 'z'){
				to_child_2[j] = child_r[i];
				j++;
			}
	    }
		
	write(pfd2[1], to_child_2, sizeof(to_child_2));
}
void child_2_Write(){

	char read_parent[104];
	int i, j;
	int count = 0;
	int nr_cara = 0;
	char  buf;
	char verify[105];
	
	FILE *stream;
	if((stream= fopen("statistica.txt", "w")) == NULL){
		printf("couldn't open statistica.txt\n");
		exit(1);
		}
	
	read(pfd2[0], read_parent, sizeof(read_parent));
		
		int aux[strlen(read_parent) - 1];
		for(i=0; i < strlen(read_parent); i++)
			aux[i]=0;
		
		strcpy(verify, read_parent);
		
		for(i = 0; i < strlen(read_parent); i++){
			for(j = 0; j< strlen(read_parent); j++){
				if( verify[j] == read_parent[i]){
					verify[j] = '*';
					count++;
				}
			}
			if(count > 0){
				buf = read_parent[i];
				fprintf(stream, "%c -> %d\r\n", buf, count);
				fprintf(stream, "\n");
				aux[i] = count;
			}
			count = 0;
		}
	for(i = 0; i < strlen(read_parent); i++){
		if(aux[i] == 1){
			nr_cara+=1;
		printf("count = %d  string->%c\n", aux[i], read_parent[i]);
		}
	}

	char nr = (char)nr_cara;
    write(pfd3[1], &nr, sizeof(nr));
	
	fclose(stream);
}

void parent_afis(){
	int buf;
	
	if(read(pfd3[0], &buf, sizeof(buf)) > 0)
		printf("Numarul de caractere disctinte este: %d\n", buf);
}

int main(int argc, char *argv[]){
     
	 pid_t pid[2];
	 pid_t w1, w2;
	 
	 int status1, status2;
	 
	 if(pipe(pfd) < 0 || pipe(pfd2) < 0 || pipe(pfd3) < 0){
		printf("Eroare la creearea pipe-ului\n");
		exit(EXIT_FAILURE);
		}
	if((pid[0] = fork()) < 0 || (pid[1] = fork()) < 0){
		printf("Eroare la fork\n");
		exit(EXIT_FAILURE);
		}
		
	if(pid[0] == 0){
		close(pfd[1]);
		close(pfd2[0]);
		
		child_1_ReadAndWrite();
		close(pfd[0]);
		close(pfd2[1]);
		return EXIT_SUCCESS;
	}
	else if(pid[1] == 0){
		close(pfd2[1]);
		close(pfd3[0]);
		child_2_Write();
		close(pfd2[0]);
		close(pfd3[1]);
		
		return EXIT_SUCCESS;
	}
	else{
	    close(pfd[0]);
		parent_write();
		close(pfd[1]);
		
		close(pfd3[1]);
		parent_afis();
		close(pfd2[0]);
		
		w1 = waitpid(pid[0], &status1, WUNTRACED | WCONTINUED);
		w2 = waitpid(pid[1], &status2, WUNTRACED | WCONTINUED);
			
            if (w1 == -1 && w2 == -1) {
                perror("waitpid");
                exit(EXIT_FAILURE);
            }
			else{
				 printf("exited, status=%d\n", WEXITSTATUS(status1));
				 printf("exited, status=%d\n", WEXITSTATUS(status2));
			}
				
		return EXIT_SUCCESS;
	}
}