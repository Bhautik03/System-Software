/*
============================================================================
Name : 27helper or sender.c
Author : Bhautik Vekariya
Description : Write a program to receive messages from the message queue. 
 	          a. with 0 as a flag 
 	          b. with IPC_NOWAIT as a flag 
Date: 28 Sept, 2025.
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

struct msgbuf{
	long mtype;
	char mytext[100];

};

int main(){
	key_t key;
	int msgid;

	struct msgbuf message;

	key = ftok("queueFile", 65);
	msgid = msgget(key, 0666 | IPC_CREAT);

	message.mtype  = 1;
	strcpy(message.mytext, "I am sender\n");

	msgsnd(msgid, &message, sizeof(message.mytext), 0);
	printf("Message sent from sender side is: %s\n", message.mytext);

	return 0;
}

/*
============================================================================
bhautik@bhautik:~/SS/HO2/27$ ./27sender
Message sent from sender side is: I am sender
============================================================================
*/