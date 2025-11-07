/*
============================================================================
Name : 21a.c
Author : Bhautik Vekariya
Description : Write two programs so that both can communicate by FIFO -Use two way communications. 
Date: 28 Sept, 2025.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd1, fd2;
    char *p1 = "send_reci";
    char *p2 = "reci_send";
    char buf[50];

    fd1 = open(p1, O_WRONLY);  
    fd2 = open(p2, O_RDONLY); 

    write(fd1, "Message from the sender!!!\n", sizeof("Message from the sender!!!\n"));

    read(fd2, buf, sizeof(buf));
    printf("Message received by sender:- %s\n", buf);

    close(fd1);
    close(fd2);
    return 0;
}



/*
============================================================================
bhautik@bhautik:~/SS/HO2/21$ gcc 21a.c -o 21a
bhautik@bhautik:~/SS/HO2/21$ ./21a
Message received by sender:- Message from the receiver!!!
============================================================================
*/
