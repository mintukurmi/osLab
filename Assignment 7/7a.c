#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main () {
   
   char* file = "file.txt"; // file to open
   int fd;                // file descriptor
   struct flock fl; 

   printf ("Opening file... %s\n", file);

   // Opening a file descriptor to the file.
   fd = open (file, O_WRONLY);
   
   printf ("Locking...\n");
   memset (&fl, 0, sizeof(fl)); // Init the flock structure.
   fl.l_type = F_WRLCK;
    
   // locking the file.
   fcntl (fd, F_SETLKW, &fl);

   printf ("Locked. \nPress any Enter to unlock... ");
   // waiting for user to press enter key
   getchar ();

   printf ("Unlocking... ");
   fl.l_type = F_UNLCK; // Release the lock
   fcntl (fd, F_SETLKW, &fl); // applying the unclock operation
   printf ("Done\n");

   close (fd);
   return 0;
}
