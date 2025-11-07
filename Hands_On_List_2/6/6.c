/*
============================================================================
Name : 6.c
Author : Bhautik Vekariya
Description : Write a simple program to create three threads.
Date: 28 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <pthread.h>

void* thread_func(void* arg) {
    printf("This is thread %d\n", *(int*)arg);
    return NULL;
}

int main() {
    pthread_t threads[3];
    int ids[3] = {1, 2, 3};

    for(int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, thread_func, &ids[i]);
    }

    for(int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/HO2/6$ gcc 6.c
bhautik@bhautik:~/SS/HO2/6$ ./a.out
This is thread 1
This is thread 2
This is thread 3
============================================================================
*/
