#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t returnValue = fork();
    char *args[] = {"./execv", NULL};
    int status;
    if (returnValue > 0)
    {
        wait(&status);
        printf("From parent process \n");
        printf("Returned value of the child process is %d\n", WIFEXITED(status));
        printf("%d is the pid of the parent\n", getpid());
        printf("%d is the pid of the parent's parent\n", getppid());
    }
    else if (returnValue == 0)
    {
        printf("Inside child process\n");
        //printf("%s is name of the main process\n", argv[0]);
        execv(args[0], args);
        printf("%d is the pid of the child\t", getpid());
        printf("%d is the pid of the parent\t", getppid());
    }
    else
    {
        printf("Error occured in creating the child process\n");
        exit(1); // abnormal termination
    }

    printf("\n");
    exit(0); // successfull termination
}