
/*
============================================================================
Name : 30b.c
Author : Bhautik Vekariya
Description : Write a program to create a shared memory.
	          b. attach with O_RDONLY and check whether you are able to overwrite.
Date: 28 Sept, 2025.
============================================================================
*/



#include<sys/shm.h>
#include<stdio.h>
#include<string.h>

int main(){
	int key, shmid;
	char *data;

	key = ftok("sharedMem", 65);
	shmid = shmget(key, 1024, 0);
	data = shmat(shmid, 0, SHM_RDONLY);

	printf("Text from shared Memory : %s\n", data);
	strcpy(data,"hiii");

	shmdt(data);
	return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/HO2/30$ gcc 30a.c
bhautik@bhautik:~/SS/HO2/30$ ./a.out
Enter the text:How
The shared memory id is 7

bhautik@bhautik:~/SS/HO2/30$ gcc 30b.c -o 30b
bhautik@bhautik:~/SS/HO2/30$ ./30b
Text from shared Memory : Hello

Segmentation fault (core dumped)
============================================================================
*/

