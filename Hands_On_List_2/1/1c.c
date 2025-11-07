/*
============================================================================
Name : 1c.c
Author : Bhautik Vekariya
Description : Write a separate program (for each time domain) to set a interval 
	      timer in 10sec and 10micro second
 	      c. ITIMER_PROF 
Date: 28 Sept, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int sig) {
    printf("ITIMER_PROF expired Signal: %d\n", sig);
}

int main() {
    struct itimerval t;
    signal(SIGPROF, handler);
    t.it_interval.tv_sec = 10;
    t.it_interval.tv_usec = 10;
    t.it_value.tv_sec = 10;
    t.it_value.tv_usec = 10;
    
    if (setitimer(ITIMER_PROF, &t, NULL) == -1) {
        perror("setitimer");
        exit(1);
    }

    while (1) {}
}

/*
============================================================================
bhautik@bhautik:~/SS/HO2/1$ gcc 1c.c
bhautik@bhautik:~/SS/HO2/1$ ./a.out
ITIMER_PROF expired Signal: 27
ITIMER_PROF expired Signal: 27
ITIMER_PROF expired Signal: 27
============================================================================
*/
