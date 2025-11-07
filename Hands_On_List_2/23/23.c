/*
============================================================================
Name : 23.c
Author : Bhautik Vekariya
Description : Write a program to print the maximum number of files can be opened 
	      within a process and  size of a pipe (circular buffer). 
Date: 28 Sept, 2025.
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>
#include<fcntl.h>

int main(){

	struct rlimit r;
	getrlimit(RLIMIT_NOFILE, &r);

	printf("Max number of files that can be opened :%ld\n", (long)r.rlim_cur);

	int fd[2];
	pipe(fd);

	long pipe_size = fpathconf(fd[0], _PC_PIPE_BUF);
	printf("pipe size: %ld\n", pipe_size);

	close(fd[0]);
	close(fd[1]);
	return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/HO2/23$ gcc 23.c
bhautik@bhautik:~/SS/HO2/23$ ./a.out
Max number of files that can be opened :1048576
pipe size: 4096
============================================================================
*/
