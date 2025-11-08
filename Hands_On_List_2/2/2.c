/*
============================================================================
Name : 2.c
Author : Bhautik Vekariya
Description : Write a program to print the system resource limits. Use getrlimit system call.
Date: 28 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

void print_limit(int resource, const char *name) {
    struct rlimit limit;
    
    getrlimit(resource, &limit);
    
    printf("%s: soft = %ld, hard = %ld\n", name, (limit.rlim_cur == RLIM_INFINITY) ? -1 : (long)limit.rlim_cur, (limit.rlim_max == RLIM_INFINITY) ? -1 : (long)limit.rlim_max);
}

int main() {
    print_limit(RLIMIT_CPU, "CPU time");
    print_limit(RLIMIT_FSIZE, "File size");
    print_limit(RLIMIT_DATA, "Data seg size");
    print_limit(RLIMIT_STACK, "Stack size");
    print_limit(RLIMIT_CORE, "Core file size");
    print_limit(RLIMIT_RSS, "Resident set");
    print_limit(RLIMIT_NOFILE, "Open files");
    print_limit(RLIMIT_AS, "Address space");
    print_limit(RLIMIT_NPROC, "Processes");
    print_limit(RLIMIT_MEMLOCK, "Locked memory");
    print_limit(RLIMIT_SIGPENDING, "Pending signals");
    print_limit(RLIMIT_MSGQUEUE, "Msg queue size");
    print_limit(RLIMIT_NICE, "Nice value");
    print_limit(RLIMIT_RTPRIO, "Real-time prio");
    print_limit(RLIMIT_RTTIME, "RT cpu time");
    return 0;
}

/*
============================================================================
bhautik@bhautik:~/SS/HO2/2$ gcc 2.c
bhautik@bhautik:~/SS/HO2/2$ ./a.out
CPU time: soft = -1, hard = -1
File size: soft = -1, hard = -1
Data seg size: soft = -1, hard = -1
Stack size: soft = 8388608, hard = -1
Core file size: soft = 0, hard = -1
Resident set: soft = -1, hard = -1
Open files: soft = 1048576, hard = 1048576
Address space: soft = -1, hard = -1
Processes: soft = 28481, hard = 28481
Locked memory: soft = 953049088, hard = 953049088
Pending signals: soft = 28481, hard = 28481
Msg queue size: soft = 819200, hard = 819200
Nice value: soft = 0, hard = 0
Real-time prio: soft = 0, hard = 0
RT cpu time: soft = 200000, hard = 200000
============================================================================
*/
