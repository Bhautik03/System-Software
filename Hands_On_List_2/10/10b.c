/*
============================================================================
Name : 10b.c
Author : Bhautik Vekariya
Description : Write a separate program using sigaction system call to catch the following signals.
 b. SIGINT
Date: 28 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handler(int sig, siginfo_t *si, void *unused) {
    printf("Caught SIGINT: %d\n", sig);
    exit(0);
}

int main() {
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGINT, &sa, NULL);

    while(1) pause();

    return 0;
}

/*
============================================================================
bhautik@bhautik:~/SS/HO2/10$ gcc 10b.c
bhautik@bhautik:~/SS/HO2/10$ ./a.out
^CCaught SIGINT: 2
============================================================================
*/
