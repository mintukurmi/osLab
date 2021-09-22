/**
 *  2(a). Write a C program that takes as input a list of processes, their arrival times and their CPU
    burst times. Schedule the processes into the CPU using Longest Time First (LJF) and Shortest 
    Remaining Time First (SRTF) algorithms. For any tie breaking condition apply FCFS algorithm. 
    Print the Gantt chart. Also compute their average waiting time and average turn around time.
 */

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    char name[10];
    int arrival_time;
    int burst_time;
} Process;

// function declarations
void printProcessInfo(Process *processes, int n);
void readProcessInfo(Process *processes, int n);
void FCFS(Process *processes, int n, int *turn_around_time, int *waiting_time);

int main()
{

    int total_processes;

    printf("\n Enter the total no of processes: ");
    scanf("%d", &total_processes);
    printf("\n You entered: %d \n", total_processes);

    Process process_queue[total_processes];    // process queue
    Process process_schedule[total_processes]; // final schedule

    int turn_around_time[total_processes];
    int waiting_time[total_processes];

    readProcessInfo(process_queue, total_processes);
    printProcessInfo(process_queue, total_processes);

    FCFS(process_queue, total_processes, turn_around_time, waiting_time);

    // int i = 0;
    // for (i = 0; i < total_processes; i++)
    // {
    //     printf("P%d - %d", i, wating_time[i]);
    // }

    return 0;
}

// read Process list from user
void readProcessInfo(Process *processes, int n)
{
    int i = 0; //loop var
    for (i = 0; i < n; i++)
    {
        Process P;

        printf("\n Enter Process Name: ");
        scanf("%s", P.name);

        printf("\n Enter Process Arrival Time: ");
        scanf("%d", &P.arrival_time);

        printf("\n Enter Process Burst time: ");
        scanf("%d", &P.burst_time);

        processes[i] = P;
    }
}

// print Processes info
void printProcessInfo(Process *processes, int n)
{
    int i = 0; //loop var
    printf("\n All Processces in queue are:");

    for (i = 0; i < n; i++)
    {
        printf("\n Process Name: %s", processes[i].name);
        printf("\n Process Arrival Time: %d", processes[i].arrival_time);
        printf("\n Process Burst Time: %d", processes[i].burst_time);
        printf("\n");
    }
}

/// FCFS
void FCFS(Process *processes, int n, int *turn_around_time, int *waiting_time)
{
    int i = 0;

    int completion_time = 0;

    for (int i = 0; i < n; i++)
    {

        int start = completion_time;
        completion_time = start + processes[i].burst_time;
        printf("\t %d -> %d", i, completion_time);

        turn_around_time[i] = completion_time - start;
        printf("\n TAT for %d is %d \n", i, turn_around_time[i]);
        // waiting_time[i] = turn_around_time[i] - processes[i].burst_time;
    }

    // for (i = 0; i < n; i++)
    // {
    //     printf("P%d - %d", i, waiting_time[i]);
    // }
}