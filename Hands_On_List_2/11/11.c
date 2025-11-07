/*
============================================================================
Name : 11.c
Author : Bhautik Vekariya
Description : Write a program to ignore a SIGINT signal then reset the default 
	      action of the SIGINT signal - use sigaction system call.
Date: 28 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    struct sigaction sa_ignore, sa_default;

    sa_ignore.sa_handler = SIG_IGN;
    sigemptyset(&sa_ignore.sa_mask);
    sa_ignore.sa_flags = 0;
    sigaction(SIGINT, &sa_ignore, NULL);

    printf("SIGINT is now ignored. Try pressing Ctrl+C.\n");
    sleep(5);

    sa_default.sa_handler = SIG_DFL;
    sigemptyset(&sa_default.sa_mask);
    sa_default.sa_flags = 0;
    sigaction(SIGINT, &sa_default, NULL);

    printf("SIGINT reset to default. Try pressing Ctrl+C again.\n");
    sleep(5);

    return 0;
}

/*
============================================================================
bhautik@bhautik:~/SS/HO2/11$ gcc 11.c
bhautik@bhautik:~/SS/HO2/11$ ./a.out
SIGINT is now ignored. Try pressing Ctrl+C.
^C^C^CSIGINT reset to default. Try pressing Ctrl+C again.
^C
============================================================================
*/

