/*
============================================================================
Name : 29.c
Author : Bhautik Vekariya
Description : Write a program to remove the message queue. 
Date: 28 Sept, 2025.
============================================================================
*/


#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t k = ftok("queueFile", 65);
    int msgqid = msgget(k, IPC_CREAT | 0664);
    printf("Message queue id: %d\n", msgqid);
    getchar();
    
    msgctl(msgqid, IPC_RMID, NULL);    
    return 0;
}



/*
============================================================================
bhautik@bhautik:~/SS/HO2/29$ gcc 29.c
bhautik@bhautik:~/SS/HO2/29$ ./a.out
Message queue id: 3

bhautik@bhautik:~/SS/HO2/29$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x41061bb4 0          bhautik-ve 666        100          1           
0x410629be 1          bhautik-ve 666        0            0           
0x4106192b 2          bhautik-ve 644        0            0           
0xffffffff 3          bhautik-ve 664        0            0     

bhautik@bhautik:~/SS/HO2/29$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x41061bb4 0          bhautik-ve 666        100          1           
0x410629be 1          bhautik-ve 666        0            0           
0x4106192b 2          bhautik-ve 644        0            0 
============================================================================
*/
