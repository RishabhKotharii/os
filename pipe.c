#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

#define MAX 100
int main(){

    int filesdes1[2],filesdes2[2],n;
    char messagetosend[MAX],messagereceived[MAX];
    pid_t pid;

    if(pipe(filesdes1)<0){
        printf("Error ");
        exit(0);
        
    }
    if(pipe(filesdes2)<0){
        printf("Error ");
        exit(0);

    }
    if((pid = fork())<0){
        printf("Error ");
        exit(0);

    }
    if(pid > 0){
        close (filesdes1[0]);
        close (filesdes2[1]);

        printf("Parent : Enter a message for child:\n");
        scanf("%s",messagetosend);
        write(filesdes1[1],messagetosend,MAX);
        n = read(filesdes2[0],messagereceived,MAX);
        printf("Parent: Message received to child : %s\n",messagereceived);
        close (filesdes1[1]);
        close (filesdes2[0]);

    }else {
        close (filesdes1[1]);
        close (filesdes2[0]);
        n = read(filesdes1[0],messagereceived,MAX);
        printf("Message receivved from child :%s\n",messagereceived);
        printf("Child : Enter the reply for parent \n");
        scanf("%s",messagetosend);
        write(filesdes2[1],messagetosend, strlen(messagetosend) + 1);
        close (filesdes1[0]);
        close (filesdes2[1]);

    }

}