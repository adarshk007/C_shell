#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/wait.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h> 
#include <unistd.h>
#define GREEN  "\x1B[32m"
#define BLUE  "\x1B[34m"
#define SIZE 200
void echo();

void pwd();
void cd();
void history();
int main(){
char command[SIZE];
while(1){


printf("shell $ ");
char  *str1[200] ;

 char  str[200] ;
  fgets(str,100,stdin);
   int count=0;
   char *token;
   char *temp=strtok(str,"\n");
   token = strtok(temp," ");
   int i=0;
   while( token != NULL ) {
	str1[i]=token;
    	token = strtok(NULL," ");
	i=i+1;
   }
	str1[i]=NULL;
	count=i;
char *p;
char c[256];	
p=getcwd(c,sizeof(c));
strcat(p,"/");
strcat(p,str1[0]);
strcat(p,".out");
char* q=str1[1];
char* r=str1[2];
int cpid = fork();
if (cpid == -1) {
    perror("fork");
} else if (cpid == 0) {
	if (strcmp(str1[0],"ls")==0 || strcmp(str1[0],"rm")==0 || strcmp(str1[0],"mkDir")==0 || strcmp(str1[0],"date")==0||strcmp(str1[0],"cat")==0)
	{
	execvp(p,str1);
    perror("execvp");
    _exit(1);	
	}
	else if(strcmp(str1[0],"echo")==0 || strcmp(str1[0],"history")==0 || strcmp(str1[0],"cd")==0 || strcmp(str1[0],"pwd")==0||strcmp(str1[0],"exit")==0){
		if(strcmp(str1[0],"exit")==0){
			break;
		}
		else if(strcmp(str1[0],"echo")==0){
			echo();
		}
		else if(strcmp(str1[0],"pwd")==0){
			pwd();
		}
		
		else if(strcmp(str1[0],"history")==0){
			printf("%s\n","Sorry :( haven't implimented" );
		}
	}
	else{
		printf("command not found" );
	}
    
} else {
    if (waitpid(cpid, 0, 0) < 0)
        perror("waitpid");
}
}

return 0;
}

void echo(){
	char w[SIZE]="adarsh good";
	char *p="-n";
	if(p=="-e"){
		printf("%s",w);
		printf("\n");
		}
	if(p=="-n"){
		printf("%s",w);
	}
}


void pwd(){
	char *p;
	char c[256];	
	p=getcwd(c,sizeof(c));
	printf("%s\n",p);
}
void cd(){
char *p;
	char c[256];	
	p=getcwd(c,sizeof(c));
}




