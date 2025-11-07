/*
============================================================================
Name : 10c.c
Author : Bhautik Vekariya
Description : Write a separate program using sigaction system call to catch the following signals.
 c. SIGFPE
Date: 28 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig, siginfo_t *si, void *unused) {
    printf("Caught SIGFPE: %d\n", sig);
    exit(1);
}

int main() {
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGFPE, &sa, NULL);

    int x = 1/0;

    return 0;
}

/*
============================================================================
bhautik@bhautik:~/SS/HO2/10$ gcc 10c.c
bhautik@bhautik:~/SS/HO2/10$ ./a.out
Caught SIGFPE: 8
============================================================================
*/
