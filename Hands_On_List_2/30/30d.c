/*
============================================================================
Name : 30d.c
Author : Bhautik Vekariya
Description : Write a program to create a shared memory.
	          d. Remove the shared memory
Date: 28 Sept, 2025.
============================================================================
*/



#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>


int main(){
	int key, shmid;
	key = ftok("sharedMem", 65);

	shmid = shmget(key, 1024, 0666 | IPC_CREAT);
	getchar();
	shmctl(shmid, IPC_RMID, NULL);

	return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/HO2/30$ gcc 30a.c
bhautik@bhautik:~/SS/HO2/30$ ./a.out
Enter the text:Hello
The shared memory id is 7

bhautik@bhautik:~/SS/HO2/30$ gcc 30d.c -o 30d
bhautik@bhautik:~/SS/HO2/30$ ./30d
                    
------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0x41068256 7          bhautik-ve 744        1024       0                       

bhautik@bhautik:~/SS/HO2/30$ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
============================================================================
*/

