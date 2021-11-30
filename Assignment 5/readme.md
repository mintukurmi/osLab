## Assignment 5


/* You need to put proper explanatory comment in your program to demonstrate the purpose 
and why you have used the C statements and system calls */


### Assignment 5(a):-
 Write a C program called Program1 which is responsible for creating a named PIPE or 
FIFO with necessary permission for all users by using the mknod( ) system call. Now, you keep 
the facility to read the information from the FIFO if any other process writes some information 
into the FIFO and as well as keep the facility to write some information into the FIFO, so that 
Program2 can read it.  

Again write another C program called Program2 which is responsible for taking the user input 
and write it back to the FIFO so that Program1 can read it. Moreover, you have to provide the 
facility to read the FIFO in this program.  

(N.B. - First run the Program1 and keep it in running state in the background. Then run the 
Program2 which will take user input string and write the input string into the FIFO. Then 
Program1 will read it from the FIFO and display it and after that Program1 will write something 
into the FIFO as ACKNOWLEDGEMENT and program2 will read the ACKNOWLEDGEMENT string 
from the FIFO. In Program2, you may take the input string as a command line argument)
  
Hints: 
 * To keep synchronize the Program1 execution with Program2 execution and vice versa, 
 You may need to use the sleep () system call
