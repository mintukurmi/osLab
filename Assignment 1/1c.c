#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *args[] = {"./execv", argv[0], NULL};
    int status;

    pid_t res = fork();

    if (res == 0)
    {
        printf(" =============== From child process ================== \n");
        execv(args[0], args);
        printf("\n From child process, PID: %d", getpid());
        printf("\n From child process, PPID: %d", getppid());
        printf("\n");
    }
    else if (res > 0)
    {
        wait(&status);
        printf(" =============== From parent process ================== \n");
        printf("\n From parent process, PID: %d", getpid());
        printf("\n From parent process, PPID: %d", getppid());
        printf("\n Returned value of the child process: %d\n", WIFEXITED(status));
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