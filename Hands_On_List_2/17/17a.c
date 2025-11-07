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

int main() {
    int fd[2];
    pid_t pid;

    pipe(fd);
    pid = fork();

    if (pid == 0) {
        close(fd[0]);             
        close(1);                
        dup(fd[1]);               
        close(fd[1]);            
        execlp("ls", "ls", "-l", NULL);
        perror("execlp ls");
        exit(1);
    } 
    
    else {
        close(fd[1]);             
        close(0);                
        dup(fd[0]);              
        close(fd[0]);            
        execlp("wc", "wc", NULL);
        perror("execlp wc");
        exit(1);
    }

    return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/HO2/17$ gcc 17a.c -o 17a
bhautik@bhautik:~/SS/HO2/17$ ./17a
      3      20     151
bhautik@bhautik:~/SS/HO2/17$ ls -l | wc
      3      20     151
============================================================================
*/
