/*
============================================================================
Name : 4.c
Author : Bhautik Vekariya
Description : Write a program to measure how much time is taken to execute 
	      100 getppid ( ) system call. Use time stamp counter. 
Date: 28 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

uint64_t rdtsc(){
    unsigned int lowerHalf, upperHalf;
    asm volatile("rdtsc" : "=a"(lowerHalf), "=d"(upperHalf));
    return ((uint64_t)upperHalf << 32) | lowerHalf;
}

int main() {
    uint64_t start, end;
    start = rdtsc();

    for(int i = 0; i < 100; i++) {
        getppid();
    }

    end = rdtsc();
    printf("CPU cycles for 100 getppid() calls: %lu\n", end - start);

    return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/HO2/4$ gcc 4.c
bhautik@bhautik:~/SS/HO2/4$ ./a.out
CPU cycles for 100 getppid() calls: 172656
============================================================================
*/
