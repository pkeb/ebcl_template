/**
* Copyright (c) 2025 Elektrobit Automotive GmbH
* License: MIT
**/

#define _GNU_SOURCE
#include <time.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <sys/ioctl.h>
#include <stdlib.h>

void print_usage(const char* app_name) {
    printf("%s <options>\n", app_name);
    printf("  -h: Print this message and exit\n");
    printf("  -s: Make a safe syscall\n");
    printf("  -u: Make an unsafe syscall\n");
}


int main(int argc, char* argv[])
{
    int return_code = 0, c;
    int make_safe_call = 0;
    int make_unsafe_call = 0;

    printf("Hello from the LiSA Demo\n");

    while( 0 == return_code && -1 != (c = getopt(argc, argv, "hsu")))
    {
        switch(c)
        {
            case 'h':
                print_usage(argv[0]);
                exit(0);
            break;
            case 's':
                make_safe_call = 1;
                break;
            case 'u':
                make_unsafe_call = 1;
                break;
            case '?':
            default:
                fprintf(stderr, "Unknown command line option.\n");
                print_usage(argv[0]);
                return_code = 1;
            break;
        }
    }

    if (! make_safe_call && ! make_unsafe_call) {
        fprintf(stderr, "Must specify at least one safe/unsafe option.\n");
        print_usage(argv[0]);
        exit(1);
    }

    if (make_safe_call) {
        printf("Making safe syscall");
        // TODO: Make safe syscall        
    }
    if (make_unsafe_call) {
        printf("Making unsafe syscall");
        // TODO: Make unsafe syscall
    }

    return 0; 
}
