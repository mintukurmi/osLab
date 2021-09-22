/**
 *  Assignment 2(c):-
    Write a C program that takes as input a list of processes, their arrival times and their CPU
    burst times. Schedule the processes into the CPU using both preemptive and non-preemptive
    Priority based scheduling algorithms. For any tie breaking condition apply FCFS algorithm. Print 
    the Gantt chart. Also compute their average waiting time and average turn around time.
 */

/*  This program is for : 2(c)  non-preemptive Priority based scheduling algorithm    */

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
    int priority;
    int remaining_burst_time;
    int is_completed; // 0 for false, 1 for true
} Process;

// functions declarations
void readProcessInfo(Process *processes, int n);
void printProcessInfo(Process *processes, int n, char title[50]);
void sort_by_arrival_time(Process *arr, int n);
void non_p_priority(Process queue[], int n, Process *schedule);
void print_gantt_chart(Process *schedule, int n);
void print_avg_time(Process *schedule, int n);

// main part of the program
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
    printProcessInfo(process_queue, total_processes, "All processes in th Queue");

    // sorting
    sort_by_arrival_time(process_queue, total_processes);

    printProcessInfo(process_queue, total_processes, "All processes after sorting by arrival time");

    // Shortest Remaining Time First Scheduling
    printf("\n The final Non-premptive Priority schedule: \n");
    non_p_priority(process_queue, total_processes, process_schedule);

    // printing gantt chart
    print_gantt_chart(process_schedule, total_processes);

    // print the avg time
    print_avg_time(process_schedule, total_processes);

    return 0;
}

/* * ----------- Funtions defs -------------- * */
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

        printf("\n Enter Process Priority: ");
        scanf("%d", &P.priority);

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
        printf("\n Process Priority: %d", processes[i].priority);

        printf("\n");
    }
}

// Non premptive Priority Scheduling algo
void non_p_priority(Process queue[], int n, Process *schedule)
{
    int current_time = 0;
    int executed = 0;

    int i = 0; // loop var

    while (executed != n)
    {
        int idx = 0;
        int max_priority = 0;

        for (i = 0; i < n; i++)
        {
            if (queue[i].priority > max_priority && queue[i].is_completed == 0)
            {
                idx = i;
                max_priority = queue[i].priority;
            }
        }

        if (idx != -1)
        {
            // if process with larger brust time found
            if (current_time == 0)
            {
                current_time = queue[idx].arrival_time;
            }

            queue[idx].start_time = current_time;

            queue[idx].completion_time = current_time + queue[idx].burst_time;

            queue[idx].turnaround_time = queue[idx].completion_time - queue[idx].arrival_time;
            queue[idx].waiting_time = queue[idx].turnaround_time - queue[idx].burst_time;

            if (queue[idx].waiting_time < 0)
            {
                queue[idx].waiting_time = 0;
            }

            queue[idx].response_time = queue[idx].start_time - queue[idx].arrival_time;

            // increasing the time; i.e. executing the process
            current_time += queue[idx].burst_time;
            queue[idx].is_completed = 1;

            printf(" -> %d ", queue[idx].pid);

            schedule[executed] = queue[idx];

            executed++; // increment executed processes counter
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
    puts("+-----+--------------+------------+------------+--------------+-----------------+");
    puts("| PID | Arrival Time | Burst Time | Priority | Waiting Time | Turnaround Time |");
    puts("+-----+--------------+------------+------------+--------------+-----------------+");

    for (i = 0; i < n; i++)
    {
        printf("| %d  |      %d      |     %d     |     %d     |      %d      |        %d       |\n", schedule[i].pid, schedule[i].arrival_time, schedule[i].burst_time, schedule[i].priority, schedule[i].waiting_time, schedule[i].turnaround_time);
        puts("+-----+------------+------------+--------------+--------------+-----------------+");
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