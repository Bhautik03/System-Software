/*
============================================================================
Name : 17a.c
Author : Bhautik Vekariya
Description : Write a program to execute ls -l | wc.
              a. use dup
              b. use dup2
              c. use fcntl 
Date: 28 Sept, 2025.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd[2];
    pid_t pid;

    pipe(fd);
    pid = fork();

    if (pid == 0) {
        close(fd[0]);
        close(STDOUT_FILENO);
        fcntl(fd[1], F_DUPFD, STDOUT_FILENO);
        close(fd[1]);
        execlp("ls", "ls", "-l", NULL);
        perror("execlp ls");
        exit(1);
    }

    else {
        close(fd[1]);
        close(STDIN_FILENO);
        fcntl(fd[0], F_DUPFD, STDIN_FILENO);
        close(fd[0]);
        execlp("wc", "wc", NULL);
        perror("execlp wc");
        exit(1);
    }

    return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/HO2/17$ gcc 17c.c -o 17c
bhautik@bhautik:~/SS/HO2/17$ ./17c
      7      56     435
bhautik@bhautik:~/SS/HO2/17$ ls -l | wc
      7      56     435
============================================================================
*/
