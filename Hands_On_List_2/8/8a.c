/*
============================================================================
Name : 8a.c
Author : Bhautik Vekariya
Description : Write a separate program using signal system call to catch the following signals.
 	          a. SIGSEGV
Date: 28 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig) { printf("Caught SIGSEGV: %d\n", sig); exit(1); }

int main() {
    signal(SIGSEGV, handler);
    int *p = NULL;
    *p = 10;
    return 0;
}

/*
============================================================================
bhautik@bhautik:~/SS/HO2/8$ gcc 8a.c
bhautik@bhautik:~/SS/HO2/8$ ./a.out
Caught SIGSEGV: 11
============================================================================
*/
