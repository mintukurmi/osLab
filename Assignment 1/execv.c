
//EXECV.c

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int i;

    printf("\n User-defined program ran inside child process.");
    printf("\n Program name of child process is : %s", argv[1]);
    printf("\n");
    return 0;
}