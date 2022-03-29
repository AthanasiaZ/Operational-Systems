#include <stdio.h>
#include<stdlib.h>
#include <time.h>
#include<limits.h>
#include <sys/types.h>
#include <unistd.h>
#include <semaphore.h>
#include <signal.h>



int heap[1000000], heapSize;
time_t t;
sem_t semaphore;
int pid ;
int randNum;
int heapSave[8];
int heapElements=100;

void EnterHeap(int count );
void Init();
void Insert(int element);
int DeleteMin();
void PrintHeap();

int main()
{




    sem_init(&semaphore, 0, 1);

      printf("Before heap insertion\n");
      for(int i=0 ; i<heapElements ; i++)
    {
      pid=fork();

    if(pid==0)
      {

        sem_wait(&semaphore);
        EnterHeap(i);
        sem_post(&semaphore);



      }

      else
      {
        wait(NULL);
      }




    }
    printf("\nAfter heap insertion\n");
    PrintHeap();
    printf("\n");



        kill(pid,SIGKILL);












  /*  for(int i =0 ; i<5 ; i++)
    printf(" minimum %d\n",DeleteMin());*/



    return 0 ;
}

void EnterHeap(int count )
{

      sleep(1);
      srand((unsigned) time(&t));
      randNum=rand()%1000;
      printf("%d\n",randNum);
      Insert(randNum);


  }

  void PrintHeap()
  {

        for(int i=0 ; i<heapElements;i++)
        {
          printf("%d\n",DeleteMin());
        }


    }










/*Declaring heap globally so that we do not need to pass it as an argument every time*/

/* Heap implemented  here is Min Heap */





/*Initialize Heap*/

void Init() {

    heapSize = 0;

    heap[0] = -INT_MAX;

}



/*Insert an element into the heap */

void Insert(int element) {

    heapSize++;

    heap[heapSize] = element; /*Insert in the last place*/

    /*Adjust its position*/

    int now = heapSize;

    while (heap[now / 2] > element) {

        heap[now] = heap[now / 2];

        now /= 2;

    }

    heap[now] = element;

}



int DeleteMin() {

    /* heap[1] is the minimum element. So we remove heap[1]. Size of the heap is decreased.

     Now heap[1] has to be filled. We put the last element in its place and see if it fits.

     If it does not fit, take minimum element among both its children and replaces parent with it.

     Again See if the last element fits in that place.*/

    int minElement, lastElement, child, now;

    minElement = heap[1];

    lastElement = heap[heapSize--];

    /* now refers to the index at which we are now */

    for (now = 1; now * 2 <= heapSize; now = child) {

        /* child is the index of the element which is minimum among both the children */

        /* Indexes of children are i*2 and i*2 + 1*/

        child = now * 2;

        /*child!=heapSize beacuse heap[heapSize+1] does not exist, which means it has only one

         child */

        if (child != heapSize && heap[child + 1] < heap[child]) {

            child++;

        }

        /* To check if the last element fits ot not it suffices to check if the last element

         is less than the minimum element among both the children*/

        if (lastElement > heap[child]) {

            heap[now] = heap[child];

        } else /* It fits there */

        {

            break;

        }

    }

    heap[now] = lastElement;

    return minElement;

}
