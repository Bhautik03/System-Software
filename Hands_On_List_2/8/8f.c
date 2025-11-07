/*
============================================================================
Name : 8f.c
Author : Bhautik Vekariya
Description : Write a separate program using signal system call to catch the following signals.
 	          f. SIGVTALRM (use setitimer system call)
Date: 28 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

void handler(int sig) {
    printf("Caught SIGVTALRM: %d\n", sig);
    exit(0);
}

int main() {
    signal(SIGVTALRM, handler);

    struct itimerval it;
    it.it_value.tv_sec = 1;
    it.it_value.tv_usec = 0;
    it.it_interval.tv_sec = 1;
    it.it_interval.tv_usec = 0;

    setitimer(ITIMER_VIRTUAL, &it, NULL);
    while(1) {
        for (volatile long i = 0; i < 1000000; i++);
    }
    return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/HO2/8$ gcc 8f.c
bhautik@bhautik:~/SS/HO2/8$ ./a.out
Caught SIGVTALRM: 26
============================================================================
*/
