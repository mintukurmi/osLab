#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/file.h>

int main(){

    struct flock fl;
    int fd; // file descriptor

    fl.l_type   = F_WRLCK;  /* read/write lock */
    fl.l_whence = SEEK_SET; /* beginning of file */
    fl.l_start  = 0;        /* offset from l_whence */
    fl.l_len    = 0;        /* length, 0 = to EOF */
    fl.l_pid    = getpid(); /* PID */

    fd = open("file.txt", O_RDWR | O_EXCL, 0444); /* not 100% sure if O_EXCL needed */

    printf("\n Applying lock \n");
    
    fcntl(fd, F_SETLK, &fl); /* set lock */
    printf("\n %d", fcntl(fd, F_SETLK, &fl); /* set lock */);

    usleep(10000000);

    printf("\n release lock \n");

    fl.l_type   = F_UNLCK;
    // fcntl(fd, F_SETLK, &fl); /* unset lock */

    return 0;
}