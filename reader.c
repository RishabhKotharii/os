#include<stdio.h>
#include<semaphore.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int rdc = 0;
int sharedvar = 100;
sem_t mutex,wrt;
pthread_t writers[5],readers[5];

void *reader(void *param){
    sem_wait(&mutex);
    rdc++;
    if(rdc == 1)
        sem_wait(&wrt);
    sem_post(&mutex);
    printf("\n%d readers are reading sharedvar %d",rdc,sharedvar);
    sem_wait(&mutex);
    rdc--;
    if(rdc == 0)
    sem_post(&wrt);
    sem_post(&mutex);
    printf("\n%d readers have entered ",rdc+1);
    
    
}
void *writer(void *param){
    printf("\nWriter has entered the CS");
    sem_wait(&wrt);
    printf("\nWriter is writing in CS");
    sharedvar++;
    printf("\nWriter has updated sharedvar to %d",sharedvar);
    sem_post(&wrt);
    printf("\nWriter is out of the CS");
}

int main (){
    int n;
    printf("\nEnter the number oof readers");
    scanf("%d",&n);
    sem_init(&mutex,0,1);
    sem_init(&wrt,0,1);
    for(int i=0;i<n;i++){
        pthread_create(&writers[i],NULL,writer,NULL);
        pthread_create(&readers[i],NULL,reader,NULL);
    }
    for(int i=0;i<n;i++){
        pthread_join(writers[i],NULL);
        pthread_join(readers[i],NULL); 
     }


}