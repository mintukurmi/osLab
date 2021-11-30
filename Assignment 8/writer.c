#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/sem.h>
#include <fcntl.h>


#define SEM1_KEY (key_t)888
#define SEM2_KEY (key_t)1234

int main(){
    int semProd, semCon;

    struct sembuf sem_op;
    
    int i=0;  // loop var
    FILE *fd;

    semProd = semget(SEM1_KEY, 1, IPC_CREAT | 0666);  // creating/accessing the producer semaphore
    if(semProd < 0)
    {
        fprintf(stderr, "\nSEMGET Failed\n");
        exit(EXIT_FAILURE);
    }

    semCon = semget(SEM2_KEY, 1, IPC_CREAT | 0666);     //creating the consumer semaphore
    if(semCon < 0)
    {
        fprintf(stderr, "\nSEMGET Failed\n");
        exit(EXIT_FAILURE);
    }


    for (i=0; i<5; i++){
        sem_op.sem_num=0;
        sem_op.sem_op=-1;  // decrementing semaphore value
        sem_op.sem_flg=0;
        semop(semCon,&sem_op,1);    // lock applied   

        
        fd=fopen("/home/xcoder/Desktop/file.txt","a+");
        fputs("Hello \n", fd);
        printf("Writing Data: Hello\n");
        getchar();
        fclose(fd);

        sem_op.sem_num=0;
        sem_op.sem_op=1;    // incrementing semaphore value
        sem_op.sem_flg=0;
        semop(semProd,&sem_op,1);/*lock released */
    }

    return 0;
}