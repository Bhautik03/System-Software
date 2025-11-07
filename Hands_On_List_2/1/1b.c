/*
============================================================================
Name : 1b.c
Author : Bhautik Vekariya
Description : Write a separate program (for each time domain) to set a interval 
              timer in 10sec and 10micro second
	      b. ITIMER_VIRTUAL
Date: 28 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int sig) {
    printf("ITIMER_VIRTUAL expired Signal: %d\n", sig);
}

int main() {
    struct itimerval t;
    signal(SIGVTALRM, handler);
    t.it_interval.tv_sec = 10;
    t.it_interval.tv_usec = 10;
    t.it_value.tv_sec = 10;
    t.it_value.tv_usec = 10;
    
    if (setitimer(ITIMER_VIRTUAL, &t, NULL) == -1) {
        perror("setitimer");
        exit(1);
    }

    while (1) {}
}


/*
============================================================================
bhautik@bhautik:~/SS/HO2/1$ gcc 1b.c
bhautik@bhautik:~/SS/HO2/1$ ./a.out
ITIMER_VIRTUAL expired Signal: 26
ITIMER_VIRTUAL expired Signal: 26
ITIMER_VIRTUAL expired Signal: 26
ITIMER_VIRTUAL expired Signal: 26
============================================================================
*/
