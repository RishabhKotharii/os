#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

#define MAX 100
int main(){
    int n,filesdes1[2],filesdes2[2];
    char messagetosend[MAX],messagereceived[MAX];

    pid_t pid;

    if(pipe(filesdes1)<0){
        printf("error in creation");
    }

    if(pipe(filesdes2)<0){
        printf("error in creation");
    }

    if((pid = fork())<0){
        printf("error in creation");
    }
    if(pid > 0){
        close (filesdes1[0]);
        close (filesdes2[1]);
        printf("ENTER THE MESSAGE TO SEND :");
        scanf("%s",messagetosend);
        write (filesdes1[1],messagetosend,MAX);
        n = read (filesdes2[0],messagereceived,MAX);
        printf("Parent: Received from child %s",messagereceived);
        close (filesdes1[1]);
        close (filesdes2[0]);

    }
    else {
        close (filesdes1[1]);
        close (filesdes2[0]);
        n = read(filesdes1[0],messagereceived, MAX);
        printf("Parent:receiver from child : %s",messagereceived);
        printf("Enter a reply for parent");
        scanf("%s",messagetosend);
        write(filesdes2[1],messagetosend,strlen(messagetosend)+1);
        close (filesdes1[0]);
        close (filesdes2[1]);
    }
    return 0;
}
