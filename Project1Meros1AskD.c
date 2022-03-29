#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void foo();


int main()
{
    //time_t start; erwthma d me time()
    int child_s;
    clock_t start,end,result;

    //time(&start);
    start = clock();
    printf("Αρχική τιμή δευτερολέπτων = %ld\n", start);//arxiki timi xronoy

    int i=0;
    while(i<100)
    {
        if(fork() == 0)//dimiourgei 100 paidia
        {
            foo();
          //printf("[son] pid %d from [parent] pid %d\n",getpid(),getppid());
            exit(0);
        }
        i++;
    }

   for(int i=0;i<100;i++)
    {
      wait(NULL);
    }


    if(i==99)
    {
      for(int j=0;j<100;j++)
      {
        pid_t waitp= waitpid(-1,&child_s,0);
      }
    }

  //  time_t end;


    //time(&end);
    end = clock();
    printf("Τελική τιμή δευτερολέπτων = %ld\n", end); //xronos cpu otan teleionei to programma.
    //time_t result;

    result=end-start;
    printf("%ld\n",result); // sinolikos xronos ektelesis programatos
    result=result/100;
    printf("%ld ",result);//mesos xronos ektelesis diergasias






}
void foo()
 {

 int x=0;
  x=x+10;

}
