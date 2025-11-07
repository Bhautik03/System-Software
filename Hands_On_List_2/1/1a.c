/*
============================================================================
Name : 1a.c
Author : Bhautik Vekariya
Description : Write a separate program (for each time domain) to set a interval 
	      timer in 10sec and 10micro second
 	      a. ITIMER_REAL 
Date: 28 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int sig) {
    printf("ITIMER_REAL expired Signal: %d\n", sig);
}

int main() {
    struct itimerval t;
    signal(SIGALRM, handler);
    t.it_interval.tv_sec = 10;
    t.it_interval.tv_usec = 10;
    t.it_value.tv_sec = 10;
    t.it_value.tv_usec = 10;
    
    if (setitimer(ITIMER_REAL, &t, NULL) == -1) {
        perror("setitimer");
        exit(1);
    }

    while (1) pause();
}

/*
============================================================================
bhautik@bhautik:~/SS/HO2/1$ gcc 1a.c
bhautik@bhautik:~/SS/HO2/1$ ./a.out
ITIMER_REAL expired Signal: 14
ITIMER_REAL expired Signal: 14
ITIMER_REAL expired Signal: 14
============================================================================
*/
