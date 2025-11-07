/*
============================================================================
Name : 33client.c
Author : Bhautik Vekariya
Description : Write a program to communicate between two machines using socket. 
Date: 28 Sept, 2025.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<errno.h>

int main(){
	struct sockaddr_in serv;
	
	int sd = socket(AF_INET, SOCK_STREAM, 0);
	if(sd < 0) exit(1);
	serv.sin_family = AF_INET;	
	serv.sin_port = htons(5100);
	serv.sin_addr.s_addr =inet_addr("127.0.0.1");
	

	char* msg = "Hello server\n";
	if(connect(sd,(struct sockaddr *) &serv, sizeof(serv))<0){ 
		perror("Connection Issue\n");	
		exit(1);
	}
	write(sd, msg, strlen(msg)+1);
	close(sd);
	return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/HO2/33$ gcc 33server.c -o server
bhautik@bhautik:~/SS/HO2/33$ gcc 33client.c -o client
bhautik@bhautik:~/SS/HO2/33$ ./server
Message from CLient:Hello server
bhautik@bhautik:~/SS/HO2/33$ ./client
============================================================================
*/