/*
============================================================================
Name : 9.c
Author : Bhautik Vekariya
Description : Write a program to ignore a SIGINT signal then reset the default 
	      action of the SIGINT signal - Use signal system call.
Date:28 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    signal(SIGINT, SIG_IGN);
    printf("SIGINT is now ignored. Try pressing Ctrl+C.\n");
    sleep(5);

    signal(SIGINT, SIG_DFL);
    printf("SIGINT reset to default. Try pressing Ctrl+C again.\n");
    sleep(5);

    return 0;
}

/*
============================================================================
bhautik@bhautik:~/SS/HO2/9$ gcc 9.c
bhautik@bhautik:~/SS/HO2/9$ ./a.out
SIGINT is now ignored. Try pressing Ctrl+C.
^CSIGINT reset to default. Try pressing Ctrl+C again.
^C
============================================================================
*/

