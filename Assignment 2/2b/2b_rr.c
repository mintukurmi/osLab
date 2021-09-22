
/**
 *  Assignment 2(b):-
    Write a C program that takes as input a list of processes, their arrival times and their CPU
    burst times. Schedule the processes into the CPU using Round Robin algorithm. Take the time 
    quantum as user input. Print the Gantt chart. Also compute their average waiting time and 
    average turn around time.
 */

/*  This program is for: 2(b) Round Robin algorithm   */

#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int pid;
    int arrival_time;
    int burst_time;
    int turnaround_time;
    int waiting_time;
    int start_time;
    int completion_time;
    int response_time;
    int remaining_burst_time;
    int is_completed; // 0 for false, 1 for true
} Process;

typedef struct
{
    Process data;
    Process *next;
} Node;

typedef struct
{
    Node *front;
    Node *rear;
} Queue;

// functions declarations
void readProcessInfo(Process *processes, int n);
void printProcessInfo(Process *processes, int n, char title[50]);
void sort_by_arrival_time(Process *arr, int n);
void RoundRobin(Process queue[], int n, Process *schedule, int quantum);
void print_gantt_chart(Process *schedule, int n);
void print_avg_time(Process *schedule, int n);

// main part of the program
int main()
{

    int total_processes, quantum = 0;

    printf("\n Enter the total no of processes: ");
    scanf("%d", &total_processes);
    printf("\n You entered: %d \n", total_processes);

    Process process_queue[total_processes];    // process queue
    Process process_schedule[total_processes]; // final schedule

    int turn_around_time[total_processes];
    int waiting_time[total_processes];

    readProcessInfo(process_queue, total_processes);
    printProcessInfo(process_queue, total_processes, "All processes in th Queue");

    // sorting
    sort_by_arrival_time(process_queue, total_processes);

    printProcessInfo(process_queue, total_processes, "All processes after sorting by arrival time");

    // getting quantum for RR
    printf("\n Enter the quantum: ");
    scanf("%d", &quantum);
    // Shortest Remaining Time First Scheduling
    printf("\n The final Round Robin schedule: \n");
    RoundRobin(process_queue, total_processes, process_schedule, quantum);

    // printing gantt chart
    print_gantt_chart(process_schedule, total_processes);

    // print the avg time
    print_avg_time(process_schedule, total_processes);

    return 0;
}

// read Process list from user
void readProcessInfo(Process processes[], int n)
{
    int i = 0; //loop var
    for (i = 0; i < n; i++)
    {
        Process P;

        printf("\n Enter Process ID: ");
        scanf("%d", &P.pid);

        printf("\n Enter Process Arrival Time: ");
        scanf("%d", &P.arrival_time);

        printf("\n Enter Process Burst time: ");
        scanf("%d", &P.burst_time);

        // setting other properties to zero
        P.completion_time = 0;
        P.is_completed = 0; // false
        P.response_time = 0;
        P.start_time = 0;
        P.turnaround_time = 0;
        P.waiting_time = 0;
        P.remaining_burst_time = P.burst_time;

        processes[i] = P;
    }
}

// print Processes info
void printProcessInfo(Process processes[], int n, char title[50])
{
    int i = 0; //loop var
    puts("\n+--------------------------------------------------------+");
    printf("\n %s:", title);

    for (i = 0; i < n; i++)
    {
        printf("\n Process ID: %d", processes[i].pid);
        printf("\n Process Arrival Time: %d", processes[i].arrival_time);
        printf("\n Process Burst Time: %d", processes[i].burst_time);

        printf("\n");
    }
}

// Round Robin Algo
void RoundRobin(Process process_queue[], int n, Process *schedule, int quantum)
{
    int current_time = 0;
    int executed = 0;
    int prev = 0;

    int i = 0; // loop var

    while (executed != n)
    {

        for (i = 0; i < n; i++)
        {
            int idx = i;

            if (process_queue[idx].is_completed == 1)
            {
                continue;
            }

            if (process_queue[idx].remaining_burst_time == process_queue[idx].burst_time)
            {
                process_queue[idx].start_time = (current_time > process_queue[idx].arrival_time) ? current_time : process_queue[idx].arrival_time;
                current_time = process_queue[idx].start_time;
            }

            if (process_queue[idx].remaining_burst_time - quantum > 0)
            {
                process_queue[idx].remaining_burst_time -= quantum;
                current_time += quantum;
                printf(" -> %d", process_queue[idx].pid);
            }
            else
            {
                printf(" -> %d", process_queue[idx].pid);
                current_time += process_queue[idx].remaining_burst_time;
                process_queue[idx].remaining_burst_time = 0;
                process_queue[idx].is_completed = 1;
                schedule[executed] = process_queue[idx];

                process_queue[idx].completion_time = current_time;
                process_queue[idx].turnaround_time = process_queue[idx].completion_time - process_queue[idx].arrival_time;
                process_queue[idx].waiting_time = process_queue[idx].turnaround_time - process_queue[idx].burst_time;
                process_queue[idx].response_time = process_queue[idx].start_time - process_queue[idx].arrival_time;

                schedule[executed] = process_queue[idx];
                executed++;
            }
        }
    }
}

// A function to sort processes by their arrival time in ascending order
void sort_by_arrival_time(Process arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        // sorting items with their priority
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j].arrival_time > arr[j + 1].arrival_time)
            {
                Process temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// print gantt chart

void print_gantt_chart(Process schedule[], int n)
{
    int i;

    printf("\n \t\t\t Gantt Chart\t\t\n");
    puts("+-----+--------------+------------+--------------+-----------------+");
    puts("| PID | Arrival Time | Burst Time | Waiting Time | Turnaround Time |");
    puts("+-----+--------------+------------+--------------+-----------------+");

    for (i = 0; i < n; i++)
    {
        printf("| %d  |      %d      |     %d     |      %d      |        %d       |\n", schedule[i].pid, schedule[i].arrival_time, schedule[i].burst_time, schedule[i].waiting_time, schedule[i].turnaround_time);
        puts("+-----+------------+--------------+--------------+-----------------+");
    }
}

// printng avg time
void print_avg_time(Process schedule[], int n)
{
    int i = 0; // loop var
    float avg_waiting_time = 0;
    float avg_turnaround_time = 0;

    for (i = 0; i < n; i++)
    {
        avg_waiting_time += schedule[i].waiting_time;
        avg_turnaround_time += schedule[i].turnaround_time;
    }

    printf("\n Avg waiting time: %f", avg_waiting_time / n);
    printf("\n Avg turn around time: %f \n", avg_turnaround_time / n);
}