/*
============================================================================
Name : 34a.c
Author : Bhautik Vekariya
Description : 34. Write a program to create a concurrent server. 
              a. use fork 
Date: 28 Sept, 2025.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 8081
#define BUFFER_SIZE 1024

void handle_client(int client_sock) {
    char buffer[BUFFER_SIZE];
    int n;

    
    n = read(client_sock, buffer, sizeof(buffer) - 1);
    if (n > 0) {
        buffer[n] = '\0';
        printf("Received from client: %s\n", buffer);
       
        write(client_sock, buffer, strlen(buffer));
    }

    close(client_sock);
    printf("Client disconnected\n");
}

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
   

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
     

    listen(server_sock, 5);
    printf("Server listening on port %d\n", PORT);

    while (1) {
        client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &client_len);
       

      
        if (fork() == 0) {
            close(server_sock); 
            handle_client(client_sock);
            exit(0);
        }

        close(client_sock);
    }

    close(server_sock);
    return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/HO2/34/a$ gcc 34aclient.c -o client
bhautik@bhautik:~/SS/HO2/34/a$ gcc 34a.c -o server
bhautik@bhautik:~/SS/HO2/34/a$ ./server
Server listening on port 8081
Received from client: Bhautik

Client disconnected

bhautik@bhautik:~/SS/HO2/34/a$ ./client
Enter message: Bhautik
Server replied: Bhautik
============================================================================
*/