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
    time_t mytime;
     char *f=argv[1];
    mytime = time(NULL);
    struct tm *info;
    char *p=argv[1];
    if(strcmp(p,"-u")==0){
	   char *p[]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
	char *w[]={"JAN","FEB","MAR","APR","MAY","JNE","JLY","AUG","SEP","OCT","NOV","DEC"};
	   info=gmtime(&mytime);
           printf("%s %s %d %d:%d:%d %s %d \n",p[(info->tm_wday)%7],w[(info->tm_mon)%12] ,info-> tm_mday,info->tm_hour,info->tm_min,info->tm_sec,"UTC",1900+info->tm_year);

	}
    else if(strcmp(p,"-I")==0){
	info=gmtime(&mytime);
	printf("%d-%d-%d \n",1900+info->tm_year,(info->tm_mon)+1 ,info-> tm_mday);
		}

    else{

    printf("%s %s","IST,", ctime(&mytime));
}
return 0;
}
