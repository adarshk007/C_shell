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
int main(int args,char* argv[]){
	char c[256];
	char *f=argv[1];
	char *w=argv[2];
	char *p;
	if(strcmp(f,"-v")==0){
		p=getcwd(c,sizeof(c));
		strcat(p,"/");
		strcat(p,w);
		int r=mkdir(p,0700);
		
	if(r==-1){
			printf("mkdir: cannot create directory \"%s\" already exists. \n",++w);
			}
	else if(strlen(w)==0){
		printf("missing operand \nTry 'mkdir --help' for more information\n");
	}
	else{

	printf("mkdir: created directory %s \n",w);
	}
	
	}
	else if(strcmp(f,"-p")==0){
		p=getcwd(c,sizeof(c));
		strcat(p,"/");
		strcat(p,w);
		int r=mkdir(p,0700);
		if(strlen(w)==0){
			printf("missing operand \nTry 'mkdir --help' for more information\n");

		}
	}

	else{	p=getcwd(c,sizeof(c));
		strcat(p,"/");
		strcat(p,f);
		int r=mkdir(p,0700);
		if(r==-1){
			printf("mkdir: cannot create directory \"%s\" already exists. \n",++w);
			}
		if(strlen(w)==0){
			printf("missing operand \nTry 'mkdir --help' for more information\n");

		}

	}
return 0;
}
