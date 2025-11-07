/*
============================================================================
Name : 32d.c
Author : Bhautik Vekariya
Description : Write a program to implement semaphore to protect any critical section.  
              d. remove the created semaphore 
Date: 28 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#define SEM_KEY 5150

int main() {
    int semid;   
    semid = semget(SEM_KEY, 1, 0666 |IPC_CREAT);
    
    sleep(50);

    (semctl(semid, 0, IPC_RMID) == -1); 
       
    printf("Semaphore with key %d removed successfully.\n", SEM_KEY);
    return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/HO2/32/d$ ./a.out
Semaphore with key 5150 removed successfully.

Before completing sleep cycle
bhautik@bhautik:~/SS/HO2/32/d$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
0x00007ffd 0          bhautik-ve 666        1       

After completing the sleep cycle
bhautik@bhautik:~/SS/HO2/32/d$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
============================================================================
*/