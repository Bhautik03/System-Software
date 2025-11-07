/*
============================================================================
Name : 31b.c
Author : Bhautik Vekariya
Description : Write a program to create a semaphore and initialize value to the semaphore.
              a. create a binary semaphore
              b. create a counting semaphore 
Date: 28 Sept, 2025.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

int main() {
    sem_t cSem;

    if (sem_init(&cSem, 0, 10) != 0) {
        perror("Initialization failed");
        exit(1);
    }

    printf("Counting semaphore initialized with value 10\n");

    sem_destroy(&cSem);
    return 0;
}



/*
============================================================================
bhautik@bhautik:~/SS/HO2/31$ gcc 31b.c -o 31b
bhautik@bhautik:~/SS/HO2/31$ ./31b
Counting semaphore initialized with value 10
============================================================================
*/
