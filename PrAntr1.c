#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

							//******First problem******\\

int main(int argc, char *argv[]){
    
	char current_dir[1024];
	DIR *dir;
	struct dirent *buf;
	char file[10];
	unsigned char just_once = 0;
	
	if(argc < 2){
		printf("Incompleted arguments\n");
		exit(EXIT_FAILURE);
	}
     
	if(getcwd(current_dir,sizeof(current_dir)) == NULL){
		perror("getcwd() error");
		exit(EXIT_FAILURE);
	}
     
	 if((dir = opendir(current_dir)) == NULL){
		perror("opendir() error");
		exit(EXIT_FAILURE);
		}
	
	else{
		while((buf = readdir(dir)) != NULL){
			if( !strcmp(buf->d_name, ".") || !strcmp(buf->d_name, ".."))
				continue;
			strcpy(file, "");
			strcpy(file, buf->d_name +(strlen(buf->d_name) - strlen(argv[1])));
			
			if(!strcmp(file, argv[1]) && strcmp(buf->d_name, "PrAntr1.exe") != 0 && strcmp(buf->d_name, "PrAntr1.c") != 0){
				if(!strcmp(argv[2], "uw")) 
						chmod(buf->d_name, S_IWUSR);
				else if(!strcmp(argv[2], "uwr"))
						chmod(buf->d_name, S_IWUSR | S_IRUSR);
				else if(!strcmp(argv[2], "uwrx"))
						chmod(buf->d_name, S_IWUSR | S_IRUSR | S_IXUSR);
				else if(!strcmp(argv[2], "ux"))
						chmod(buf->d_name, S_IXUSR);
				else if(!strcmp(argv[2], "uwx"))
						chmod(buf->d_name, S_IWUSR | S_IXUSR);
				else if(!strcmp(argv[2], "urx"))
						chmod(buf->d_name, S_IRUSR | S_IXUSR);
				else if(!strcmp(argv[2], "ur"))
						chmod(buf->d_name, S_IRUSR);
				else if(!strcmp(argv[2], "urx"))
						chmod(buf->d_name, S_IXUSR | S_IRUSR);
				else if(!strcmp(argv[2], "gw"))
						chmod(buf->d_name, S_IWGRP);
				else if(!strcmp(argv[2], "gr"))
						chmod(buf->d_name, S_IRGRP);
				else if(!strcmp(argv[2], "gx"))
						chmod(buf->d_name, S_IXGRP);
				else if(!strcmp(argv[2], "gwr"))
						chmod(buf->d_name, S_IWGRP | S_IRGRP);
				else if(!strcmp(argv[2], "gwx"))
						chmod(buf->d_name, S_IXGRP | S_IWGRP);
				else if(!strcmp(argv[2], "grx"))
						chmod(buf->d_name, S_IXGRP | S_IRGRP);
				else if(!strcmp(argv[2], "gwrx"))
						chmod(buf->d_name, S_IXGRP | S_IWGRP |S_IRGRP);
				else if(!strcmp(argv[2], "ow"))
						chmod(buf->d_name, S_IWOTH);
				else if(!strcmp(argv[2], "or"))
						chmod(buf->d_name, S_IROTH);
				else if(!strcmp(argv[2], "ox"))
						chmod(buf->d_name, S_IXOTH);
				else if(!strcmp(argv[2], "owr"))
						chmod(buf->d_name, S_IWOTH | S_IROTH);
				else if(!strcmp(argv[2], "owx"))
						chmod(buf->d_name, S_IWOTH | S_IXOTH);
				else if(!strcmp(argv[2], "orx"))
						chmod(buf->d_name, S_IROTH | S_IXOTH);
				else if(!strcmp(argv[2], "owrx"))
						chmod(buf->d_name, S_IWOTH | S_IROTH | S_IXOTH);
				else if(!strcmp(argv[2], "aw"))
						chmod(buf->d_name, S_IWOTH | S_IWUSR | S_IWGRP);
				else if(!strcmp(argv[2], "ar"))
						chmod(buf->d_name, S_IROTH | S_IRUSR | S_IRGRP);
				else if(!strcmp(argv[2], "ax"))
						chmod(buf->d_name, S_IXOTH | S_IXUSR | S_IXGRP);
				else if(!strcmp(argv[2], "awr"))
						chmod(buf->d_name, S_IWOTH | S_IROTH | S_IWUSR | S_IRUSR | S_IRGRP | S_IWGRP);
				else if(!strcmp(argv[2], "awx"))
						chmod(buf->d_name, S_IWOTH | S_IXOTH | S_IWUSR | S_IXUSR | S_IXGRP | S_IWGRP);
				else if(!strcmp(argv[2], "arx"))
						chmod(buf->d_name, S_IROTH | S_IXOTH | S_IRUSR | S_IXUSR | S_IXGRP | S_IRGRP);
				else if(!strcmp(argv[2], "awrx"))
						chmod(buf->d_name, S_IWUSR | S_IRUSR | S_IXUSR | S_IWGRP | S_IRGRP | S_IXGRP | S_IWOTH | S_IROTH | S_IXOTH );
			    else if(!just_once){
					printf("I've done nothing :)\n");
					just_once = 1;
					}
				}
			}
		}
	closedir(dir);
}
