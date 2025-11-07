/*
============================================================================
Name : 8c.c
Author : Bhautik Vekariya
Description : Write a separate program using signal system call to catch the following signals.
 	          c. SIGFPE
Date: 28 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int sig) { printf("Caught SIGFPE: %d\n", sig); exit(1); }

int main() {
    signal(SIGFPE, handler);
    int x = 1 / 0;
    return 0;
}

/*
============================================================================
bhautik@bhautik:~/SS/HO2/8$ gcc 8c.c
bhautik@bhautik:~/SS/HO2/8$ ./a.out
Caught SIGFPE: 8
============================================================================
*/
