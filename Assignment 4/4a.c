#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// function defs
void handleSig(int sigNum)
{
    int buf[4]; // buffer for storing data
    int fd[2];  // file descriptors for read/write

    if (pipe(fd) < 0) // initiating the pipe
        exit(1);

    pid_t pid = fork(); // forking to create a new process

    if (pid == 0)
    {
        // inside the child process
        int id = getpid();
        write(fd[1], &id, 4); // sending the process_id stored in INT `id`

        int size;
        printf("\n\nEnter the size of Fibonacci series: ");
        scanf("%d", &size); // getting the size of the fibonacci series

        write(fd[1], &size, 4); // sending the size of the fibonacci series to parent
        /* ------------------ Fibonacci series code ------------------ */
        int n1 = 0, n2 = 1, n3; // variable to store nums
        write(fd[1], &n1, 4);   // sending 1st term of the fibonacci series
        write(fd[1], &n2, 4);   // sending 2nd term of the fibonacci series

        int i = 0;                 // loop var
        for (i = 2; i < size; ++i) //loop starts from 2 because 0 and 1 are already printed
        {
            n3 = n1 + n2;
            // sending the subsequent terms of the fibonacci series
            write(fd[1], &n3, 4);
            n1 = n2;
            n2 = n3;
        }
        /* ------------------ Fibonacci series code ------------------ */
        write(fd[1], &sigNum, 4); // sending the signal number to parent process
    }
    else if (pid > 0)
    {
        // inside the parent
        wait(NULL);   // waiting till the child process finishes executing
        close(fd[1]); // closing the pipe

        // reading the process id from child process
        read(fd[0], buf, 4);
        printf("\nThe Process id: %d\n", *((int *)buf));

        // reading the size of the fibonacci series from child process
        int size = read(fd[0], buf, 4);

        int i = 0; // loop var
        printf("\nThe fibonacci series is: ");
        for (i = 0; i <= size; i++)
        {
            read(fd[0], buf, 4);           // reading the terms of the series one by one
            printf("%d, ", *((int *)buf)); // printing it to the screen
        }

        read(fd[0], buf, 4); // reading the signal number sent by child process
        printf("\n\nThe signal number was: %d\n\n", *((int *)buf));
    }
    else
    {
        // if some error occurs while forking
        printf("\n Unable to fork.");
    }

    exit(0);
}

int main()
{
    printf("Press Ctrl + Z to initiate SIGTSTP signal.. ");

    signal(SIGTSTP, handleSig); // signal() is called to set a custom signal handler for a signal

    getchar();

    return 0;
}
