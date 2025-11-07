/*
============================================================================
Name : 27a.c
Author : Bhautik Vekariya
Description :  Write a program to receive messages from the message queue. 
 	           a. with 0 as a flag 
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
	char msgtext[100];

};

int main(){
	key_t key;
	int msgid;
	struct msgbuf message;

	key = ftok("queueFile", 65);

	msgid = msgget(key, 0666 | IPC_CREAT);

	printf("Waiting for message... \n");
	msgrcv(msgid, &message, sizeof(message.msgtext),1, 0);
	printf("Message received is :%s \n",message.msgtext);

	return 0;
}

/*
============================================================================
bhautik@bhautik:~/SS/HO2/27$ gcc 27sender.c -o 27sender
bhautik@bhautik:~/SS/HO2/27$ gcc 27b.c -o 27b
bhautik@bhautik:~/SS/HO2/27$ gcc 27a.c -o 27a
bhautik@bhautik:~/SS/HO2/27$ ./27a
Waiting for message... 
Message received is :I am sender

bhautik@bhautik:~/SS/HO2/27$ ./27sender
Message sent from sender side is: I am sender
============================================================================
*/