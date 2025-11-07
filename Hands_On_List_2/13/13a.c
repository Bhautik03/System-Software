/*
============================================================================
Name : 13a.c
Author : Bhautik Vekariya
Description : First program waiting to catch SIGSTOP signal. Demonstrates that SIGSTOP cannot be caught.
Date: 28 Sept, 2025.
============================================================================
*/


#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
    printf("Program 13a running. PID = %d\n", getpid());

    for (int i = 0; i < 15; i++) {
        printf("Waiting... %d\n", i + 1);
        sleep(1);
    }

    printf("Finished waiting. SIGSTOP could not be caught.\n");
    return 0;
}



/*
============================================================================
bhautik@bhautik:~/SS/HO2/13$ ./13a
Program 13a running. PID = 11049
Waiting... 1
Waiting... 2
Waiting... 3
Waiting... 4
Waiting... 5
Waiting... 6
Waiting... 7

[1]+  Stopped                 ./13a
============================================================================
*/

