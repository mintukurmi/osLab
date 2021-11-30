#include <stdio.h>
#include <sys/types.h>
#include <sys/time.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>


int main(){

    struct timeval start_time;
    struct timeval end_time;
    
    FILE *fptr;

    pid_t res = fork();

    // set the child process exectue in time
    gettimeofday(&start_time, NULL); 

    if (res == 0) {
        // child process       
        printf("\n Start Time");
        printf("\n seconds : %ld secs \n",start_time.tv_sec);
        printf("\n **Sleep for 5 sec... \n");
        sleep(5); // child process sleep for 2 sec
    }
    
    if(res > 0){   
        // parent process
        wait(NULL); // waiting the parent process till child executes
        
        // getting the end time of child process as the ecution comes to parent process after the child finishes executing
        gettimeofday(&end_time, NULL); 

        printf("\n End Time"); // printing the Finish time 
        printf("\n seconds : %ld secs",end_time.tv_sec);

        // timezone diff between UTC and IST - i.e, 5hr 30Min
        long int ist = 19800; // 5hr 30Min in secs

        printf("\n\n Submission time: %ld secs", start_time.tv_sec+ist);

        printf("\n Finish time: %ld secs", end_time.tv_sec+ist);
        printf("\n");

        // Writing time into file named output.txt
        fptr = fopen("output.txt","w");
        fprintf(fptr,"Submission time: %ld secs",start_time.tv_sec+ist);
        fprintf(fptr,"\nFinish time: %ld secs",end_time.tv_sec+ist);
        fclose(fptr);
    }

    return 0;
}