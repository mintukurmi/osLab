#include <stdio.h>
#include <string.h>
#include <pthread.h>

// thread function for passing into a thread
void *myFunc()
{
    printf("\n Hello World!!\n\n");
    pthread_exit(NULL);
}

int main(void)
{
    // variable for stroing thread id
    pthread_t id;

    // creating a new thread
    pthread_create(&id, NULL, myFunc, NULL);

    // Wait for myFunc() to execute;
    pthread_join(id, NULL);
}
