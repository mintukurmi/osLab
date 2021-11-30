## Assignment 3

/* You need to put proper explanatory comment in your program to demonstrate the purpose 
and why you have used the C statements and system calls */

### Assignment 3(a):-
 Write a C program by using signal() system call to handle the reception of SIGINT signal by
executing a particular (user) function, which function is responsible for creating a child process 
by using fork( ) system call and then you have to display the PROCESS ID and PARENT PROCESS 
ID from the parent process as well as from the child process.
Hints: 
* For generating, SIGINT (SIGINT is a keyboard interrupt signal) signal, you have to press 
Ctrl+C. So, by default pressing Ctrl+C in a running program leads to the termination of 
the running process. But, your program should provide a way to handle the keyboard 
interrupt through signal() system.


### Assignment 3(b):-
 Write a C program which will take the Process ID and signal ID as input to demonstrate 
the use of kill( ) system call.
Hints: 
 * For demonstrating so, you modify the assignment 3(a) to handle different signals as 
 many possible where handler of each signal prints signal number. Run the modified 
 assignment 3(a). 
 * Again from another terminal, run the assignment 3(b) which will take the Process ID 
 of the modified assignment 3(a) and any valid signal value as input.
 * Your signal handler function of the assignment 3(b) should be able to display the 
 signal ID of the generated signal.
 
 
### Assignment 3(c):-
 Write a C program to create a user level thread using system call pthread_create( ) and 
assign the thread to display the “HELLO WORLD” . Use pthread_exit() in your program (if 
possible) for terminating the thread
