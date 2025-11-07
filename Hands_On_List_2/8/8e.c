/*
============================================================================
Name : 8e.c
Author : Bhautik Vekariya
Description : Write a separate program using signal system call to catch the following signals.
 	          e. SIGALRM (use setitimer system call)
Date: 28 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

void handler(int sig) {
    printf("Caught SIGALRM (ITIMER_REAL): %d\n", sig);
    exit(0);
}

int main() {
    signal(SIGALRM, handler);

    struct itimerval it;
    it.it_value.tv_sec = 1;      
    it.it_value.tv_usec = 0;
    it.it_interval.tv_sec = 1;  
    it.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &it, NULL);

    while(1) pause();
    return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/HO2/8$ gcc 8e.c
bhautik@bhautik:~/SS/HO2/8$ ./a.out
Caught SIGALRM (ITIMER_REAL): 14
============================================================================
*/
