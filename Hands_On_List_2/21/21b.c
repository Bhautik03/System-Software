/*
============================================================================
Name : 21b.c
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
    char *p1 = "send_reci",  *p2 = "reci_send";
    char buf[50];

    fd1 = open(p1, O_RDONLY);  
    fd2 = open(p2, O_WRONLY); 

    read(fd1, buf, sizeof(buf));
    printf("Message received by receiver:- %s\n", buf);

    write(fd2, "Message from the receiver!!!\n", sizeof("Message from the receiver!!!\n"));

    close(fd1);
    close(fd2);
    return 0;
}



/*
============================================================================
bhautik@bhautik:~/SS/HO2/21$ gcc 21b.c -o 21b
bhautik@bhautik:~/SS/HO2/21$ ./21b
Message received by receiver:- Message from the sender!!!
============================================================================
*/

