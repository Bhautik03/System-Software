/*
============================================================================
Name : 20b.c
Author : Bhautik Vekariya
Description : Write two programs so that both can communicate by FIFO -Use one way communication 
Date: 28 Sept, 2025.
============================================================================
*/


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    char *path = "myfifo";
    char buf[50];

    fd = open(path, O_RDONLY);

    read(fd, buf, sizeof(buf));
    close(fd);
    printf("Message read from FIFO by receiver:- %s\n", buf);
    
    return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/HO2/20$ gcc 20b.c -o 20b
bhautik@bhautik:~/SS/HO2/20$ ./20b
Message read from FIFO by receiver:- Message from the sender...
============================================================================
*/
