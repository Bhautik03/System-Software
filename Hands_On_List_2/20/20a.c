/*
============================================================================
Name : 20a.c
Author : Bhautik Vekariya
Description : Write two programs so that both can communicate by FIFO -Use one way communication 
Date: 28 Sept, 2025.
============================================================================
*/

#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    char *path = "myfifo";

    fd = open(path, O_WRONLY);
    write(fd, "Message from the sender...", sizeof("Message from the sender..."));
    close(fd);
    printf("Sender: Message written to FIFO\n");

    return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/HO2/20$ vim 20a.c
bhautik@bhautik:~/SS/HO2/20$ gcc 20a.c -o 20a
bhautik@bhautik:~/SS/HO2/20$ ./20a
Sender: Message written to FIFO
============================================================================
*/

