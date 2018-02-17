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
	char *file=argv[2];
	FILE *point;
	char cal;
	int val;
	char *calr=NULL;
	int count=1;
	size_t len=0;
	point = fopen(file, "r");
	if(strlen(f)==0){

	    if (point == NULL)
	    {
		printf("Cannot open file \n");
		exit(0);
	    }
	    cal = fgetc(point);
	    while (cal != EOF)
	    {	count=count+1;
		printf ("%c", cal);
		cal = fgetc(point);
	    }
	fclose(point);
	 
	   }
	else if(strcmp(f,"-n")==0){
	if (point == NULL)
	    {
		printf("Cannot open file \n");
		exit(0);
	    }
	else{
	 while ((val = getline(&calr,&len, point)) != -1) {
	
	    printf("%d %s",count, calr);
		count=count+1;
	    
	}
	if (calr){
	    free(calr);
	} }
	}
	else if(strcmp(f,"-E")==0){
	if (point == NULL)
	    {
		printf("Cannot open file \n");
		exit(0);
	    }
	else{
	 while ((val = getline(&calr,&len, point)) != -1) {
		calr[val-1]=' ';
		strcat(calr,"$");
		strcat(calr,"\n");
	    printf("%s",calr);
	
	}
	if (calr){
	    free(calr);
	} }
	}
	else
	{
		printf("cat: invalid option -- '%s' \nTry 'cat --help' for more information\n",f);
	}
return 0;
 }
