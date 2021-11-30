#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// structure for message queue
struct msg_buffer {
   long msg_type;
   char msg[100];
} message;

int main() {
   key_t my_key; // vars def
   int msg_id;

   my_key = ftok("file", 65);   //create unique key
   msg_id = msgget(my_key, 0666 | IPC_CREAT);   //create message queue and return id
   message.msg_type = 1;
   
   printf("Write Message : ");
   fgets(message.msg, 100, stdin);
   msgsnd(msg_id, &message, sizeof(message), 0); //send message to server
   
   printf("Message to Server: id:%d, msg:%s \n", msg_id,message.msg); // printf msg from server
}