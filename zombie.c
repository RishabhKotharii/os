#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

pid_t pid;
void main(){
    pid = fork();
    if (pid < 0)
    printf("Error in fork execution");
    else if(pid == 0){
        printf("Parent has id %d\n",getppid());
        printf("Child has is %d\n",getpid());
    } else if(pid > 0){
        sleep (10);
        printf("***parent\n");
        system("ps -axj | tail");
    }
    exit(0);
}
