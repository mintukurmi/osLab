#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

// signal id 1
void handleSighup(int s)
{
    printf("Signal id: %d\n", s);
}
// signal id 2
void handleSigint(int s)
{
    printf("Signal id: %d\n", s);
}

// signal id 3
void handleSigQuit(int s)
{
    printf("Signal id: %d\n", s);
}

// signal id 4
void handleSigIll(int s)
{
    printf("Signal id: %d\n", s);
}

// signal id 5
void handleSigTrap(int s)
{
    printf("Signal id: %d\n", s);
}
// signal id 6
void handleSigAbrt(int s)
{
    printf("Signal id: %d\n", s);
}

// signal id 7
void handleSigBus(int s)
{
    printf("Signal id: %d\n", s);
}
// signal id 8
void handleSigFpe(int s)
{
    printf("Signal id: %d\n", s);
}
// signal id 9
void handleSigKill(int s)
{
    printf("Signal id: %d\n", s);
}
// signal id 10
void handleSigUsr1(int s)
{
    printf("Signal id: %d\n", s);
}

int main()
{
    printf("Process id: %d \n", getpid());

    signal(SIGINT, handleSigint);   // signal 1
    signal(SIGHUP, handleSighup);   // signal 2
    signal(SIGQUIT, handleSigQuit); // signal 3
    signal(SIGILL, handleSigIll);   // signal 4
    signal(SIGTRAP, handleSigTrap); // signal 5
    signal(SIGABRT, handleSigAbrt); // signal 6
    signal(SIGBUS, handleSigBus);   // signal 7
    signal(SIGFPE, handleSigFpe);   // signal 8
    signal(SIGKILL, handleSigKill); // signal 9
    signal(SIGUSR1, handleSigUsr1); // signal 10

    while (1)
    {
        //  loop to keep the program running
    }

    return 0;
}
