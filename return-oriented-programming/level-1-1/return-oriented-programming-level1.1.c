#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "util.h"

#define BUF_LEN 0x30
#define OOB_LEN 0x400
char flag[] = "/flag\0";
char name[BUF_LEN];

void gifts()
{
        __asm__ __volatile__(
                "ldr x8, [sp, #0x18]; ldp x29, x30, [sp], #0x20; ret;"
                "ldp x2, x3, [sp], #0x20; ldp x29, x30, [sp], #0x20 ; ret;"
                "ldp x0, x1, [sp], #0x10; ldp x29, x30, [sp], #0x10 ; ret;"
        );
}

void init()
{
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
	setvbuf(stderr, 0, 2, 0);
}

void read_input()
{
        char buf[BUF_LEN];

        puts("Who is your favorite Pokemon?");
        read(0, buf, OOB_LEN);
}

void play()
{
        puts("Input your name");
        read(0, name, BUF_LEN);
        printf("Hello, %s\n", name);
        read_input();
}

int main()
{
        init();
        print_desc();
        play();
        print_exit();

	return 0;
}