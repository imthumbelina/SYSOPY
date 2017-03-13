#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <sys/times.h>
#include <time.h>
 #include <sys/resource.h>
 #include <sys/time.h>

struct rusage rusage_start,rusage_end;
struct timeval user_start,user_end,system_start,system_end,real_start,real_end;
//long double user_sum, system_sum, real_sum;

void start_clock(){
  getrusage(RUSAGE_SELF,&rusage_start);
  gettimeofday(&real_start,NULL);
}
void end_clock(){
  gettimeofday(&real_end,NULL);
  getrusage(RUSAGE_SELF,&rusage_end);

  user_start=rusage_start.ru_utime; //total amount of time spend in user mode
  user_end=rusage_end.ru_utime;
  system_start=rusage_start.ru_stime;
  system_end=rusage_end.ru_stime;

//  long double se = (system_end.tv_sec - system_start.tv_sec)*1000000L + system_end.tv_usec - system_start.tv_usec;
  printf("system time %09ld ms",((system_end.tv_sec - system_start.tv_sec)*1000000L) + system_end.tv_usec - system_start.tv_usec);
  printf("user time %09ld ms",((user_end.tv_sec - user_start.tv_sec)*1000000L+ user_end.tv_usec) - user_start.tv_usec);
  printf("real time %09ld ms",((real_end.tv_sec - real_start.tv_sec)*1000000L + real_end.tv_usec) - real_start.tv_usec);


}

char *randstring(int length) {
    static int mySeed = 25011984;
    char *string = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    size_t stringLen = strlen(string);
    char *randomString = NULL;

    srand(time(NULL) * length + ++mySeed);

    if (length < 1) {
        length = 1;
    }

    randomString = malloc(sizeof(char) * (length +1));

    if (randomString) {
        short key = 0;

        for (int n = 0;n < length;n++) {
            key = rand() % stringLen;
            randomString[n] = string[key];
        }

        randomString[length] = '\0';

        return randomString;
    }
    else {
        printf("No memory");
        exit(1);
    }
}

int main() {



start_clock();
BSTNode**root=malloc(sizeof(BSTNode*));
*root = NULL;

for(int i=0;i<10000;i++){
  insert(root,randstring(6),randstring(6),randstring(6),randstring(6),randstring(6),randstring(6));
}
//printTree(*root);
end_clock();



//printTree(*root);
//cpu_time_used = ((double) (end - start)) / ticks_per_sec;
//printf("%lf",cpu_time_used);

//usuwanie całego drzewa
//deleteTree(*root);
//*root=NULL;

//usuwanie pojedynczych wezlow
//*root=delete(*root,"A");
//*root=delete(*root,"b");

//printTree(*root);
printf("%s","MakeMake");

}
