/*
============================================================================
Name : 14.c
Author : Bhautik Vekariya
Description : Write a simple program to create a pipe, write to the pipe, 
	      read from pipe and display on the monitor.
Date: 28 Sept, 2025.
============================================================================
*/


#include<stdio.h>
#include<unistd.h>


int main(){
	int fd[2];
	char buf[100];
	pipe(fd);

	write(fd[1], "How are you?\n", sizeof("How are you?\n"));
	read(fd[0], buf, sizeof(buf));
	printf("Read from pipe:- %s", buf);

	return 0;
}

/*
============================================================================
bhautik@bhautik:~/SS/HO2/14$ vim 14.c
bhautik@bhautik:~/SS/HO2/14$ gcc 14.c
bhautik@bhautik:~/SS/HO2/14$ ./a.out
Read from pipe:- How are you?
============================================================================
*/


