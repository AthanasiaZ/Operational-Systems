#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <time.h>
#include <string.h>


FILE *file;
sem_t writef;
sem_t readf;

void* FileReadOrWrite(void *ptr)
{
  int rand;
    rand=randoms();
    char c[20];
    char buf[50];


  if(rand>25)
  {

  printf("User %d entered the queue for file writing \n",rand);
  sem_wait(&writef);
  sem_wait(&readf);
  printf(" User %d entering the critical region\n",rand);

  file= fopen("fileforproject.txt","w");
  sleep(5);
  fprintf(file, "File modified by User %d \n",rand);
  fclose(file);
  sem_post(&readf);
  sem_post(&writef);

  printf("User %d is out of the critical region \n",rand );
  }
  else
  {

    //sem_wait(&writef);


    printf("User %d is reading now the file\n",rand );

    file=fopen("fileforproject.txt","r");
    //sem_wait(&readf);
      sleep(3);

    // fclose(file);
    //sem_post(&readf);
    printf("User  %d is not reading the file  \n",rand);


    //sem_post(&writef);
    //sem_post(&readf);



  }



  return NULL;
}

int randoms()
{
  int random= (rand() %(50 - 1)) + 1;

  return random;
}





 int main()
 {
  sem_init(&writef, 0, 1);
  sem_init(&readf,0,1);
  pthread_t fileWrite[9];
  pthread_t fileRead;
  int rand ;
  srand(time(0));

  //for(int i =0 ; i<5 ; i++)
      //  {



            pthread_create(&fileWrite[0], NULL, FileReadOrWrite,NULL);
            sleep(1);
            pthread_create(&fileWrite[1], NULL, FileReadOrWrite,NULL);
            sleep(1);
            pthread_create(&fileWrite[2],NULL,FileReadOrWrite,NULL);
            sleep(1);
            pthread_create(&fileWrite[3], NULL, FileReadOrWrite, NULL);
            sleep(1);
            pthread_create(&fileWrite[4], NULL, FileReadOrWrite, NULL);
            sleep(1);


            pthread_join(fileWrite[0],NULL);
            pthread_join(fileWrite[1],NULL);
            pthread_join(fileWrite[2],NULL);
            pthread_join(fileWrite[3],NULL);
            pthread_join(fileWrite[4],NULL);




      //}





  sem_destroy(&readf);
  sem_destroy(&writef);
  exit(0);
}
