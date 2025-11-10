#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

pid_t pid;
void main(){
    pid = fork();
    if (pid < 0 )
    printf("Error in fork execution");
    else if (pid > 0){
        printf("Parent process id is %d\n",getpid());
        printf("Child process id is %d\n",pid);
    } else if (pid == 0){
        
        printf("Parent process id is %d\n",getppid());
        printf("Child process id is %d\n",getpid());
        sleep(10);
        printf("Child process id is %d\n",getpid());
        printf("Parent process id is %d\n",getppid());
        
    }
} 
