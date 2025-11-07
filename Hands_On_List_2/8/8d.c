/*
============================================================================
Name : 8d.c
Author : Bhautik Vekariya
Description : Write a separate program using signal system call to catch the following signals.
 	          d. SIGALRM (use alarm system call)
Date: 28 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handler(int sig) {
    printf("Caught SIGALRM (alarm): %d\n", sig);
    exit(0);
}

int main() {
    signal(SIGALRM, handler);
    alarm(1);  
    while(1) pause();
    return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/HO2/8$ gcc 8d.c
bhautik@bhautik:~/SS/HO2/8$ ./a.out
Caught SIGALRM (alarm): 14
============================================================================
*/
