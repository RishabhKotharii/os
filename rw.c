#include<semaphore.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

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
    printf("\n%d reader are reading sharedvar %d",rdc,sharedvar);
    sem_wait(&mutex);
    rdc--;
    if(rdc == 0)
    sem_post(&wrt);
    sem_post(&mutex);
    printf("\n%d readers have entered ",rdc+1);
}

void *writer(void *param){
    printf("\nWriter is trying to enter");
    sem_wait(&wrt);
    printf("\nWriter has entered the CS");
    sharedvar++;
    printf("\nSharedvar value is changed to %d",sharedvar);
    sem_post(&wrt);
    printf("\nWriter is out of the CS");
}   

int main(){

    int n;
    printf("\nEnter the number of readers");
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