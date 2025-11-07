/*
============================================================================
Name : 12.c
Author : Bhautik Vekariya
Description : Write a program to create an orphan process. Use kill system call 
	      to send SIGKILL signal to the parent process from the child process.
Date: 28 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        exit(1);
    }

    if (pid == 0) {
        printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        sleep(2);
        kill(getppid(), SIGKILL);
        printf("Child sent SIGKILL to parent.\n");
        sleep(2);
        printf("Child's new Parent PID = %d\n", getppid());
    } 
    
    else {
        printf("Parent process: PID = %d\n", getpid());
        while(1) sleep(1);
    }

    return 0;
}

/*
============================================================================
bhautik@bhautik:~/SS/HO2/12$ gcc 12.c
bhautik@bhautik:~/SS/HO2/12$ ./a.out
Parent process: PID = 8575
Child process: PID = 8576, Parent PID = 8575
Child sent SIGKILL to parent.
Killed
Child's new Parent PID = 2182
============================================================================
*/

