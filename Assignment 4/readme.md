## Assignment 4

/* You need to put proper explanatory comment in your program to demonstrate the purpose 
and why you have used the C statements and system calls */


### Assignment 4(a):-
 
 Write a C program to handle the reception of INTERRUPT FROM THE KEYBOARD signal by 
executing a particular (user) function, which function is responsible for creating a child process 
by using fork() system call. 
Also, the child process will take an input N (N is the no. of terms to 
generate the Fibonacci series) from the user and generate the Fibonacci series up to N terms. 
Then the child process will send the Fibonacci series terms one by one to the parent process by 
using pipe() system call and the parent process will read the Fibonacci series terms one by one 
and will display it..

Before sending the Fibonacci terms one by one from the child process, first you send the 
Process ID of the child process to the parent process and read and display it in the parent 
process. Again after sending the terms one by one from the child process to the parent process, 
from the child process you send the Signal ID for which handler function has been generated 
and read and display it in the parent process.
