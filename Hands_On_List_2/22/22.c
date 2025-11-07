/*
============================================================================
Name : 22.c
Author : Bhautik Vekariya
Description : Write a program to wait for data to be written into FIFO within 
	      10 seconds, use select system call with FIFO. 
Date: 28 Sept, 2025.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/select.h>

int main() {
    int fd;
    char *path = "myfifo";
    char buf[50];
    fd_set rfds;
    struct timeval tv;
    int retval;

    fd = open(path, O_RDONLY | O_NONBLOCK);

    FD_ZERO(&rfds);
    FD_SET(fd, &rfds);

    tv.tv_sec = 10;
    tv.tv_usec = 0;

    printf("Waiting for data on FIFO (10 seconds)...\n");

    retval = select(fd + 1, &rfds, NULL, NULL, &tv);

    if (retval == -1) {
        perror("select");
	    close(fd);
        exit(1);
    } 
    
    else if (retval == 0) {
        printf("Timeout: No data within 10 seconds.\n");
    } 
    
    else {
        if (FD_ISSET(fd, &rfds)) {
            int n = read(fd, buf, sizeof(buf) - 1);
            
            if (n > 0) {
                buf[n] = '\0';
                printf("Data received: %s\n", buf);
            } 

	        else {
                printf("FIFO closed or no data.\n");
            }
        }
    }

    close(fd);
    return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/HO2/22$ gcc 22.c
bhautik@bhautik:~/SS/HO2/22$ ./a.out
Waiting for data on FIFO (10 seconds)...
Data received: Hello FIFO
============================================================================
*/
