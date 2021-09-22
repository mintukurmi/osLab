#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

// signint handler
void handleSigInt()
{
    pid_t res = fork(); //creating process a new process using fork() system call

    if (res == 0)
    { // inside child process
        printf("\nFrom Child, pid: %d", getpid());
        printf("\nFrom Child, ppid: %d \n", getppid());
        // printf("");
    }
    else if (res > 0)
    { // inside parent prcoess
        printf("\nFrom Parent, pid: %d", getpid());
        printf("\nFrom Parent, ppid: %d\n", getppid());
    }
    else
    { // if process cant be created
        printf("\nSome error occured while creating new process.\n");
    }

    exit(0); // exiting the program, otherwise it will run forever
}

int main()
{

    printf("\nPress Ctrl + C to initiate SIGINT signal.. ");

    signal(SIGINT, handleSigInt); // setting custom SIGINT signal handler

    getchar();
    // to wait for user to press CTRL + C to initiate the SIGINT signal
    return 0;
}