/*
============================================================================
Name : 3.c
Author : Bhautik Vekariya
Description : Write a program to set (maximum number of open files) system 
	      resource limit. Use setrlimit system call. 
Date: 28 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit r;
    getrlimit(RLIMIT_CPU, &r);
    printf("Before: soft=%ld, hard=%ld\n", r.rlim_cur, r.rlim_max);

    r.rlim_cur = 50;
    setrlimit(RLIMIT_CPU, &r);

    getrlimit(RLIMIT_CPU, &r);
    printf("After: soft=%ld, hard=%ld\n", r.rlim_cur, r.rlim_max);

    return 0;
}


/*
============================================================================
bhautik@bhautik:~/SS/HO2/3$ gcc 3.c
bhautik@bhautik:~/SS/HO2/3$ ./a.out
Before: soft=-1, hard=-1
After: soft=50, hard=-1
============================================================================
*/
