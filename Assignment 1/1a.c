#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{

    pid_t res = fork();

    if (res == 0)
    {
        printf("\n From child process, PID: %d", getpid());
        printf("\n From child process, PPID: %d", getppid());
        printf("\n");
    }
    else if (res > 0)
    {
        printf("\n From parent process, PID: %d", getpid());
        printf("\n From parent process, PPID: %d", getppid());
        printf("\n");
    }
    else
    {
        printf("\n Unable to create a new process");
        printf("\n");
        exit(1); // exit failure
    }
    exit(0); // exit success
}