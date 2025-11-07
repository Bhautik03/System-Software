/*
============================================================================
Name : 28.c
Author : Bhautik Vekariya
Description : Write a program to change the exiting message queue permission. (use msqid_ds structure) 
Date: 28 Sept, 2025.
============================================================================
*/


#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    struct msqid_ds buf;

    key_t k = ftok("queueFile", 65);
    int msqid = msgget(k, 0666 | IPC_CREAT);

    msgctl(msqid, IPC_STAT, &buf);
    printf("Current permission: %o\n", buf.msg_perm.mode);

    buf.msg_perm.mode = 0644;
    msgctl(msqid, IPC_SET, &buf);

    printf("Permissions changed!\n");
    printf("Updated permissions: %o\n", buf.msg_perm.mode);

    return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/HO2/28$ touch queueFile
bhautik@bhautik:~/SS/HO2/28$ gcc 28.c
bhautik@bhautik:~/SS/HO2/28$ ./a.out
Current permission: 666
Permissions changed!
Updated permissions: 644
============================================================================
*/
