/*
============================================================================
Name : 15.c
Author : Bhautik Vekariya
Description : Write a simple program to send some data from parent to the child process.
Date: 28 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd[2];        
    pid_t pid;
    char buf[50];

    pipe(fd);
    pid = fork();
    
    if (pid > 0) {
        close(fd[0]); 
        write(fd[1], "How are you??", sizeof("How are you??"));
        close(fd[1]); 
    } 
    
    else {
        close(fd[1]);
        read(fd[0], buf, sizeof(buf));
        printf("Message received by Child:- %s\n", buf);
        close(fd[0]); 
    }

    return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/HO2/15$ gcc 15.c
bhautik@bhautik:~/SS/HO2/15$ ./a.out
Message received by Child:- How are you??
============================================================================
*/

