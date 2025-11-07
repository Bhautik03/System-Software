/*
============================================================================
Name : 30c.c
Author : Bhautik Vekariya
Description : Write a program to create a shared memory.
	          c. detach the shared memory
Date: 28 Sept, 2025.
============================================================================
*/



#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>


int main(){
	int key;  
	key = ftok("sharedMem", 65);
	char *data;

	int shmid = shmget(key, 1024, 0666|IPC_CREAT);
	data = shmat(shmid, 0, 0);
	printf("Attached data :%s\n", data);
	printf("shared Memory id :%d\n", shmid);
	getchar();
	shmdt(data);
	return 0;
}

/*
============================================================================
bhautik@bhautik:~/SS/HO2/30$ gcc 30c.c -o 30c
bhautik@bhautik:~/SS/HO2/30$ ./30c
Attached data :Hello

shared Memory id :7

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0x41068256 7          bhautik-ve 744        1024       1                       

bhautik@bhautik:~/SS/HO2/30$ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0x41068256 7          bhautik-ve 744        1024       0          
============================================================================
*/

