/*
============================================================================
Name : 8b.c
Author : Bhautik Vekariya
Description : Write a separate program using signal system call to catch the following signals.
 	          b. SIGINT
Date: 28 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handler(int sig) { printf("Caught SIGINT: %d\n", sig); exit(0); }

int main() {
    signal(SIGINT, handler);
    while(1) pause();
    return 0;
}

/*
============================================================================
bhautik@bhautik:~/SS/HO2/8$ gcc 8b.c
bhautik@bhautik:~/SS/HO2/8$ ./a.out
Caught SIGINT: 2
============================================================================
*/
