/*
============================================================================
Name : 7.c
Author : Bhautik Vekariya
Description : . Write a simple program to print the created thread ids.
Date: 28 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <pthread.h>

void* thread_func(void* arg) {
    printf("Thread ID: %lu\n", pthread_self());
    return NULL;
}

int main() {
    pthread_t threads[3];

    for(int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, thread_func, NULL);
    }

    for(int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/HO2/7$ gcc 7.c
bhautik@bhautik:~/SS/HO2/7$ ./a.out
Thread ID: 131709483873984
Thread ID: 131709330781888
Thread ID: 131709475481280
============================================================================
*/
