/*
============================================================================
Name : 31a.c
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
    sem_t bSem;

    if (sem_init(&bSem, 0, 1) != 0) {
        perror("Initialization failed");
        exit(1);
    }

    printf("Binary semaphore initialized with value 1\n");
    sem_destroy(&bSem);
    return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/HO2/31$ gcc 31a.c -o 31a
bhautik@bhautik:~/SS/HO2/31$ ./31a
Binary semaphore initialized with value 1
============================================================================
*/
