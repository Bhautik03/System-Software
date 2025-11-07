/*
============================================================================
Name : 10a.c
Author : Bhautik Vekariya
Description : Write a separate program using sigaction system call to catch the following signals.
 a. SIGSEGV
Date: 28 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig, siginfo_t *si, void *unused) {
    printf("Caught SIGSEGV: %d\n", sig);
    exit(1);
}

int main() {
    struct sigaction sa;
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handler;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGSEGV, &sa, NULL);

    int *p = NULL;
    *p = 10;

    return 0;
}

/*
============================================================================
bhautik@bhautik:~/SS/HO2/10$ gcc 10a.c
bhautik@bhautik:~/SS/HO2/10$ ./a.out
Caught SIGSEGV: 11
============================================================================
*/
