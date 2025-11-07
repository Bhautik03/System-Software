/*
============================================================================
Name : 13b.c
Author : Bhautik Vekariya
Description : Second program sends SIGSTOP to the first program automatically after 3 seconds.
Date: 28 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <PID of 13a>\n", argv[0]);
        exit(1);
    }

    pid_t pid = atoi(argv[1]);

    kill(pid, SIGSTOP);
    printf("SIGSTOP sent to PID %d\n", pid);

    return 0;
}

/*
============================================================================
bhautik@bhautik:~/SS/HO2/13$ ./13b 11049
SIGSTOP sent to PID 11049
============================================================================
*/

