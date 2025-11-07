/*
============================================================================
Name : 18.c
Author : Bhautik Vekariya
Description : Write a program to find out total number of directories on the pwd.
	      execute ls -l | grep ^d | wc ? Use only dup2. 
Date: 28 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int fd1[2], fd2[2];
    pid_t pid1, pid2;

    pipe(fd1);
    pipe(fd2);

    if ((pid1 = fork()) == 0) {
        dup2(fd1[1], STDOUT_FILENO); 
        close(fd1[0]);
        close(fd1[1]);
        close(fd2[0]);
        close(fd2[1]);
        execlp("ls", "ls", "-l", NULL);
        perror("execlp ls");
        exit(1);
    }

    if ((pid2 = fork()) == 0) {
        dup2(fd1[0], STDIN_FILENO);   
        dup2(fd2[1], STDOUT_FILENO);   
        close(fd1[0]);
        close(fd1[1]);
        close(fd2[0]);
        close(fd2[1]);
        execlp("grep", "grep", "^d", NULL);
        perror("execlp grep");
        exit(1);
    }

    
    dup2(fd2[0], STDIN_FILENO); 
    close(fd1[0]);
    close(fd1[1]);
    close(fd2[0]);
    close(fd2[1]);
    execlp("wc", "wc", NULL);
    perror("execlp wc");
    exit(1);
}


/*
============================================================================
bhautik@bhautik:~/SS/HO2/18$ gcc 18.c
bhautik@bhautik:~/SS/HO2/18$ ./a.out
      1       9      70
============================================================================
*/
