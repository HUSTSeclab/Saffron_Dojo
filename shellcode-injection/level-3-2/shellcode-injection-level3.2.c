#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include "util.h"

#define BUF_LEN 0x100

char *buf;
void init()
{
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
	setvbuf(stderr, 0, 2, 0);
        buf = mmap((void *)0x12340000, 0x1000, 7, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
}

void read_input()
{
        char s[BUF_LEN];
        
        puts("Give me your input");
        scanf("%s", s);
        memmove(buf, s, BUF_LEN);
}

void play_game()
{
        read_input();
}

int main()
{
        init();
        print_desc();
        play_game();
        print_exit();

	return 0;
}