/*
============================================================================
Name : 32a.c
Author : Bhautik Vekariya
Description : Write a program to implement semaphore to protect any critical section.  
              a. rewrite the ticket number creation program using semaphore 
Date: 28 Sept, 2025.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<unistd.h>
#include<sys/shm.h>


#define SHM_KEY  5156
#define SEM_KEY 1374

struct sembuf p = {0,-1, 0};
struct sembuf v = {0, 1, 0};

int main(){

	int shmid, semid;
	int *ticket =0 ;


	shmid = shmget(SHM_KEY, sizeof(int), IPC_CREAT |0666);
	ticket = (int*) shmat(shmid, NULL,0);

	semid = semget(SEM_KEY, 1, IPC_CREAT|0666);
	semctl(semid, 0, SETVAL, 1);


	for(int i = 0; i < 5;i++){
		semop(semid, &p, 1);

		(*ticket)++;
		printf("Ticket number :%d\n", *ticket);
		fflush(stdout);	
		semop(semid, &v, 1);
		sleep(1);
	}

	shmdt(ticket);

	return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/HO2/32/a$ gcc 32a.c -o 32a
bhautik@bhautik:~/SS/HO2/32/a$ ./32a
Ticket number :11
Ticket number :13
Ticket number :15
Ticket number :17
Ticket number :19

bhautik@bhautik:~/SS/HO2/32/a$ ./32a
Ticket number :12
Ticket number :14
Ticket number :16
Ticket number :18
Ticket number :20
============================================================================
*/