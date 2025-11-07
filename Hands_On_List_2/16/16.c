/*
============================================================================
Name : 16.c
Author : Bhautik Vekariya
Description : Write a program to send and receive data from parent to child 
	      vice versa. Use two way communication.
Date: 28 Sept, 2025.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int par_child[2], child_par[2];
    pid_t pid;
    char buf[50];

    pipe(par_child);
    pipe(child_par);
    pid = fork();
    
    if (pid > 0) {
        close(par_child[0]);
        close(child_par[1]); 

        write(par_child[1], "This is Parent, How are you??", sizeof("This is Parent, How are you??"));
        close(par_child[1]);

        read(child_par[0], buf, sizeof(buf));
        printf("Received by parent:- %s\n", buf);
        close(child_par[0]);
    } 

    else {
        close(par_child[1]); 
        close(child_par[0]);

        read(par_child[0], buf, sizeof(buf));
        printf("Received by child:- %s\n", buf);
        close(par_child[0]);

        write(child_par[1], "This is child, How are you??", sizeof("This is child, How are you??"));
        close(child_par[1]);
    }

    return 0;
}

/*
============================================================================
bhautik@bhautik:~/SS/HO2/16$ gcc 16.c
bhautik@bhautik:~/SS/HO2/16$ ./a.out
Received by child:- This is Parent, How are you??
Received by parent:- This is child, How are you??
============================================================================
*/