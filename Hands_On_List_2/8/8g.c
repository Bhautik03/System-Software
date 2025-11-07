/*
============================================================================
Name : 8g.c
Author : Bhautik Vekariya
Description : Write a separate program using signal system call to catch the following signals.
 	          g. SIGPROF (use setitimer system call)
Date: 28 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handler(int sig) { printf("Caught SIGPROF: %d\n", sig); }

int main() {
    signal(SIGPROF, handler);
    struct itimerval it = {{1,0},{1,0}};
    setitimer(ITIMER_PROF, &it, NULL);
    
    while(1) {
        for (volatile long i = 0; i < 1000000; i++); 
    }
    return 0;
}

/*
============================================================================
bhautik@bhautik:~/SS/HO2/8$ gcc 8g.c
bhautik@bhautik:~/SS/HO2/8$ ./a.out
Caught SIGPROF: 27
============================================================================
*/
