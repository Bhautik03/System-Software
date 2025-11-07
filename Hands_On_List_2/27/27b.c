
/*
============================================================================
Name : 27b.c
Author : Bhautik Vekariya
Description : Write a program to receive messages from the message queue. 
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
	char mtext[100];
};

int main(){
	
	key_t key;
	int msgid;
	struct msgbuf message;

	key = ftok("queueFile", 65);
	msgid = msgget(key, 0666|IPC_CREAT);
	printf("Trying to receive message (IPC_NOWAIT )\n");
	int r = msgrcv(msgid, &message, sizeof(message.mtext), 1, IPC_NOWAIT);
	
	if(r != -1){	
		printf("Message received from message queue:- %s\n", message.mtext);
	}
	else{
		printf("Nothing I got in queue\n");
	}
	return 0;
}

/*
============================================================================
bhautik@bhautik:~/SS/HO2/27$ ./27b
Trying to receive message (IPC_NOWAIT )
Nothing I got in queue


bhautik@bhautik:~/SS/HO2/27$ ./27sender
Message sent from sender side is: I am sender
bhautik@bhautik:~/SS/HO2/27$ ./27b
Trying to receive message (IPC_NOWAIT )
Message received from message queue:- I am sender
============================================================================
*/