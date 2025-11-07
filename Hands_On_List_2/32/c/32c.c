/*
============================================================================
Name : 32c.c
Author : Bhautik Vekariya
Description : Write a program to implement semaphore to protect any critical section. 
              c. protect multiple pseudo resources ( may be two) using counting semaphore  
Date: 28 Sept, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/stat.h>

#define SEM_NAME "/write_sem"

int main()
{
    sem_t *sem;

    
    sem = sem_open(SEM_NAME, O_CREAT, 0644, 2);

    printf("Process %d: waiting for a writing...\n", getpid());
    sem_wait(sem);

    printf("Process %d: got a writer! writing...\n", getpid());
    sleep(10);

    printf("Process %d: done writing, releasing writer.\n", getpid());
    sem_post(sem);

    sem_close(sem);
    return 0;
}

/*
============================================================================
terminal 1
bhautik@bhautik:~/SS/HO2/32/c$ gcc 32c.c -o 32c
bhautik@bhautik:~/SS/HO2/32/c$ ./32c
Process 13341: waiting for a writing...
Process 13341: got a writer! writing...
Process 13341: done writing, releasing writer.

terminal 2
bhautik@bhautik:~/SS/HO2/32/c$ ./32c
Process 13343: waiting for a writing...
Process 13343: got a writer! writing...
Process 13343: done writing, releasing writer.

terminal 3
bhautik@bhautik:~/SS/HO2/32/c$ ./32c
Process 13368: waiting for a writing...
Process 13368: got a writer! writing...
Process 13368: done writing, releasing writer.
============================================================================
*/