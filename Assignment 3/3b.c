#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid;
    int sid;

    // getting process id from user
    printf("\n Enter the process id: ");
    scanf("%d", &pid);
    // getting signal id from user
    printf("\n Enter a signal id between(1-8): ");
    scanf("%d", &sid);

    // sending signal to process via its process id
    kill(pid, sid);

    return 0;
}