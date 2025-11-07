/*
============================================================================
Name : 24.c
Author : Bhautik Vekariya
Description : Write a program to create a message queue and print the key and message queue id. 
Date: 28 Sept, 2025.
============================================================================
*/


#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t k = ftok("queueFile", 65); 
    int msqid = msgget(k, 0666 | IPC_CREAT);

    printf("Message Queue created...\n");
    printf("Key:- %d\n", k);
    printf("Message Queue ID:- %d\n", msqid);

    return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/HO2/24$ touch queueFile
bhautik@bhautik:~/SS/HO2/24$ gcc 24.c
bhautik@bhautik:~/SS/HO2/24$ ./a.out
Message Queue created...
Key:- 1090918101
Message Queue ID:- 5
============================================================================
*/

