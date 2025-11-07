/*
============================================================================
Name : 26.c
Author : Bhautik Vekariya
Description : Write a program to send messages to the message queue. Check $ipcs -q 
Date: 28 Sept, 2025.
============================================================================
*/


#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msgbuf {
    long mtype;
    char mtext[100];
};

int main() {
    struct msgbuf message;

    key_t k = ftok("queueFile", 65);
    int msgqid = msgget(k, 0666 | IPC_CREAT);

    message.mtype = 1;
    strcpy(message.mtext, "Hello, this is test message!");

    if(msgsnd(msgqid, &message, sizeof(message.mtext), 0));

    printf("Message sent!\n");

    return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/HO2/26$ touch queueFile
bhautik@bhautik:~/SS/HO2/26$ gcc 26.c
bhautik@bhautik:~/SS/HO2/26$ ./a.out
Message sent!
bhautik@bhautik:~/SS/HO2/26$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0xffffffff 0          bhautik-ve 666        0            0           
0x4106248a 1          bhautik-ve 666        0            0           
0x41060c8d 2          bhautik-ve 666        0            0           
0x41061bb4 3          bhautik-ve 666        100          1           
============================================================================
*/
