#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

pid_t num_pid;

void main() {
    num_pid = fork();
    if (num_pid < 0)
    printf("Error in creating child process");
    else if (num_pid ==0)
    printf("Child process created with pid %d\n", getpid());
    else {
        printf("Parent process has pid %d\n",getpid());
        printf("Child process has pid %d\n", num_pid);
        wait(NULL);
    }
    exit(0);
}