/*
============================================================================
Name : 19.c
Author : BhautikVekariya
Description : Create a FIFO file by
			  a. mknod command
			  b. mkfifo command
			  c. use strace command to find out, which command (mknod or mkfifo) is better.
			  c. mknod system call
			  d. mkfifo library function
Date: 30 Sept, 2025.
============================================================================
*/



#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

int main(){
	system("mknod fifo_a p");
	printf("FIFO created using mknod command (fifo_a)\n");

	system("mkfifo fifo_b");
	printf("FIFO created using mkfifo command (fifo_b)\n");

	system("strace -c mkfifo fifo_c");
	printf("c.mkfifo internally calls mknod\n");

	mknod("fifo_d",S_IFIFO|0666,0);
	mkfifo("fifo_e",0666);

	return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/HO2/19$ ls -l
total 20
-rw-rw-r-- 1 bhautik-vekariya bhautik-vekariya  1013 Sep 30 23:45 19.c
-rwxrwxr-x 1 bhautik-vekariya bhautik-vekariya 16088 Sep 30 23:47 a.out
prw-rw-r-- 1 bhautik-vekariya bhautik-vekariya     0 Sep 30 23:47 fifo_a
prw-rw-r-- 1 bhautik-vekariya bhautik-vekariya     0 Sep 30 23:47 fifo_b
prw-rw-r-- 1 bhautik-vekariya bhautik-vekariya     0 Sep 30 23:47 fifo_c
prw-rw-r-- 1 bhautik-vekariya bhautik-vekariya     0 Sep 30 23:47 fifo_d
prw-rw-r-- 1 bhautik-vekariya bhautik-vekariya     0 Sep 30 23:47 fifo_e
============================================================================
*/
