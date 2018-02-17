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
	char *f=argv[1];
	int val;
	char *p;
	char c[256];
	char *w=argv[2];
	
	if(strcmp(f,"-v")==0)
	{
	p=getcwd(c,sizeof(c));
	strcat(p,"/");
	strcat(p,w);	
	val=unlink(p);
	if(val==0)
	{
	printf("removed \"%s\" \n",w);
	}
	else if(val==-1)
	{
	printf("rm: cannot remove \"%s\" : No such file or directory \n",w);		
	}
  }
	else if(strcmp(f,"-f")==0){
	p=getcwd(c,sizeof(c));
	strcat(p,"/");
	strcat(p,w);	
	val=unlink(p);
		f="-f";
		if(val==-1){
	printf("rm: cannot remove \"%s\" : No such file or directory \n",w);		
	}
		if(strlen(w)==0){
			printf("missing operand \nTry 'rm --help' for more information\n");

		}
	 }
	else{
	p=getcwd(c,sizeof(c));
	strcat(p,"/");
	strcat(p,f);	
	val=unlink(p);
 	if(val==-1){
	printf("rm: cannot remove \"%s\" : No such file or directory \n",++w);		
	}
	else if(strlen(w)==0){
			printf("missing operand \nTry 'rm --help' for more information\n");

		}
	}
return 0;
}

