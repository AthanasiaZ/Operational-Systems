#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

int n=10;
int passId[2];
pipe(passId);
pid_t cpid,ppid,mpid;

int print() {


    printf( " My parent id is:%d , My pid is:%d, My child id is:%d \n " ,   ppid ,mpid,cpid);
    return 1;
}

int func(int n)
{

    if (n == 0)
    {
        return 0;
    }
    int pid = fork();
    if (pid == -1) {
        exit(0);
    }
    if (pid==0) {
        mpid = getppid(); 
        cpid = getpid();
        print();
        ppid=getppid();


        n = n-1;
        func(n);


        exit(0);
    }
    else {

       wait(NULL);
    }
    return 0;
}


int main(int argc , char *argv[])
{
    func(n);
    return 0;
}
