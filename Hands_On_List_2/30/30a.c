/*
============================================================================
Name : 30a.c
Author : Bhautik Vekariya
Description : Write a program to create a shared memory.
	          a. write some data to the shared memory
Date: 28 Sept, 2025.
============================================================================
*/


#include<sys/shm.h>
#include<stdio.h>

int main(void){
	int key, shmid;
	char *data;

	key = ftok("sharedMem", 65);
	shmid = shmget(key, 1024, IPC_CREAT | 0744);
	data = shmat(shmid, 0, 0);

	printf("Enter the text:");
	fgets(data, 1024, stdin);
	getchar();
	printf("The shared memory id is %d\n", shmid);

	
	shmdt(data);
	return 0;
}

/*
============================================================================
bhautik@bhautik:~/SS/HO2/30$ gcc 30a.c -o 30a
bhautik@bhautik:~/SS/HO2/30$ ./30a
Enter the text:Hello

The shared memory id is 7

bhautik@bhautik:~/SS/HO2/30$ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0x41068256 7          bhautik-ve 744        1024       1                       

bhautik@bhautik:~/SS/HO2/30$ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0x41068256 7          bhautik-ve 744                     
============================================================================
*/
