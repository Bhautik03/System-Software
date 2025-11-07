/*
============================================================================
Name : 5.c
Author : Bhautik Vekariya
Description : Write a program to print the system limitation of 
 	      a. maximum length of the arguments to the exec family of functions. 
 	      b. maximum number of simultaneous process per user id. 
 	      c. number of clock ticks (jiffy) per second. 
 	      d. maximum number of open files
  	      e. size of a page
 	      f. total number of pages in the physical memory
 	      g. number of currently available pages in the physical memory. 
Date: 28 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/sysinfo.h>

int main() {
    struct rlimit rl;
    struct sysinfo info;

    long arg_max = sysconf(_SC_ARG_MAX);
    printf("Maximum length of arguments to exec: %ld\n", arg_max);

    getrlimit(RLIMIT_NPROC, &rl);
    printf("Maximum number of simultaneous processes per user: %ld\n", rl.rlim_cur);

    long ticks = sysconf(_SC_CLK_TCK);
    printf("Number of clock ticks per second: %ld\n", ticks);

    getrlimit(RLIMIT_NOFILE, &rl);
    printf("Maximum number of open files: %ld\n", rl.rlim_cur);

    long page_size = sysconf(_SC_PAGESIZE);
    printf("Size of a page: %ld bytes\n", page_size);

    sysinfo(&info);
    printf("Total number of pages in physical memory: %lu\n", info.totalram / page_size);
    printf("Number of available pages in physical memory: %lu\n", info.freeram / page_size);

    return 0;
}

/*
============================================================================
bhautik@bhautik:~/SS/HO2/5$ gcc 5.c
bhautik@bhautik:~/SS/HO2/5$ ./a.out
Maximum length of arguments to exec: 2097152
Maximum number of simultaneous processes per user: 28481
Number of clock ticks per second: 100
Maximum number of open files: 1024
Size of a page: 4096 bytes
Total number of pages in physical memory: 1861422
Number of available pages in physical memory: 686311
============================================================================
*/
