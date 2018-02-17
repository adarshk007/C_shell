#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h> 
#include <unistd.h>
#define GREEN  "\x1B[32m"
#define BLUE  "\x1B[34m"
#define SIZE 200
int main(int argc,char* argv[]){
  DIR *d;
  int val;
  char *f=argv[1];
  struct dirent **dir;
  val = scandir(".",&dir,0,alphasort);
  int i=0;
  if(f==NULL){
  for(i;i<val;i++) {
		   if(dir[i]->d_name[0]!='.'){
				printf("%s\t", dir[i]->d_name);
			}
                   
                   
               }
		printf("\n");
               free(dir);}
		
  else if(strcmp(f,"-a")==0){
	for(i;i<val;i++) {
		   
				printf("%s\t", dir[i]->d_name);
			
                   
                   
               }
		printf("\n");
               free(dir);

		}
  else if(strcmp(f,"-A")==0){
	for(i;i<val;i++) {
		   if(dir[i]->d_name[0]!='.'){
				printf("%s\t", dir[i]->d_name);
			}
                   
                   
               }
	printf("\n");
               free(dir);

	}
	else{
		printf("Wrong input \n");
	}
return 0;}

