/*
============================================================================
Name : 33server.c
Author : Bhautik Vekariya
Description : Write a program to communicate between two machines using socket. 
Date: 28 Sept, 2025.
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

int main(){
	int sd;
	struct sockaddr_in serv, cli;

	char box[1024];
	
	sd = socket(AF_INET, SOCK_STREAM, 0);
	serv.sin_family = AF_INET;
	serv.sin_addr.s_addr = INADDR_ANY;
	serv.sin_port = htons(5100);

	bind(sd, (struct sockaddr *)&serv, sizeof(serv));
	listen(sd, 5);
	socklen_t  n = sizeof(cli);
	int nsd = accept(sd,(struct sockaddr *) &cli, &n);

	int r =	read(nsd, box, sizeof(box));
	
	if(r > 0){
		box[r] = '\0';	
		printf("Message from CLient:%s\n",box);
	}
	close(nsd);
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