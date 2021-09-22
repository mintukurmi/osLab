#include <stdio.h>
#include <string.h>

struct item
{
    char item[5];
    int priority;
};

void bubbleSort(struct item *arr, int n);

int main()
{
    struct item queue[3];

    struct item p1, p2, p3;

    strcpy("P1", p1.item);
    p1.priority = 4;

    strcpy("P2", p2.item);
    p2.priority = 2;

    strcpy("P3", p3.item);
    p3.priority = 1;

    queue[0] = p1;
    queue[1] = p2;
    queue[2] = p3;

    int front = 0, rear = 3 - 1;
    int i = 0;

    // sorting the queue
    bubbleSort(queue, 3);

    for (i = 0; i < 3; i++)
    {
        printf("\n %s --> %d", queue[i].item, queue[i].priority);
    }

    return 0;
}

// A function to implement bubble sort
void bubbleSort(struct item *arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        // sorting items with their priority
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j].priority < arr[j + 1].priority)
            {
                struct item temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
