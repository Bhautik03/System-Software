/*
============================================================================
Name : 25.c
Author : Bhautik Vekariya
Description : Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
	      a. access permission
	      b. uid, gid
	      c. time of last message sent and received
	      d. time of last change in the message queue
	      e. size of the queue
	      f. number of messages in the queue
	      g. maximum number of bytes allowed
	      h. pid of the msgsnd and msgrcv
Date: 28 Sept, 2025.
============================================================================
*/


#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <time.h>

int main() {
    struct msqid_ds buf; 

    key_t k = ftok("queueFile", 65);
    int msqid = msgget(k, 0666 | IPC_CREAT);
    msgctl(msqid, IPC_STAT, &buf);

    printf("Message Queue Information!!!\n");
    printf("a. Access permissions:- %o\n", buf.msg_perm.mode);
    printf("b. UID:- %d, GID:- %d\n", buf.msg_perm.uid, buf.msg_perm.gid);
    printf("c. Time of last message sent:- %s", buf.msg_stime ? ctime(&buf.msg_stime) : "Not yet sent\n");
    printf("   Time of last message received:- %s", buf.msg_rtime ? ctime(&buf.msg_rtime) : "Not yet received\n");
    printf("d. Time of last change:- %s", ctime(&buf.msg_ctime));
    printf("e. Current size of queue:- %lu\n", buf.__msg_cbytes);
    printf("f. Number of messages in queue:- %lu\n", buf.msg_qnum);
    printf("g. Maximum number of bytes allowed:- %lu\n", buf.msg_qbytes);
    printf("h. PID of last msgsnd:- %d\n", buf.msg_lspid);
    printf("   PID of last msgrcv:- %d\n", buf.msg_lrpid);

    return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/HO2/25$ touch queueFile
bhautik@bhautik:~/SS/HO2/25$ gcc 25.c
bhautik@bhautik:~/SS/HO2/25$ ./a.out
Message Queue Information!!!
a. Access permissions:- 666
b. UID:- 1000, GID:- 1000
c. Time of last message sent:- Not yet sent
   Time of last message received:- Not yet received
d. Time of last change:- Sat Sep 20 18:17:41 2025
e. Current size of queue:- 0
f. Number of messages in queue:- 0
g. Maximum number of bytes allowed:- 16384
h. PID of last msgsnd:- 0
   PID of last msgrcv:- 0
============================================================================
*/
