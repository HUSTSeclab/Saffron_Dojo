#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include "util.h"

#define BUF_LEN 0x40
#define OOB_LEN 0x100

void init()
{
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
	setvbuf(stderr, 0, 2, 0);
}

void read_flag(char *filename)
{
	char *p;
	FILE *fp;
	char flag[BUF_LEN];

	memset(flag, 0, sizeof(flag));
	fp = fopen(filename, "r");

	if (!fp) {
		perror("[-] fopen failed");
		exit(0);
	}

	p = fgets(flag, sizeof(flag), fp);
	if (!p) {
		perror("[-] fgets failed");
		fclose(fp);
		exit(0);
	}
	
	printf("%s\n", flag);

	fclose(fp);
	exit(0);
}

void read_input()
{
	char buffer[BUF_LEN];

	printf("Say something at %p\n", buffer);
	printf(">>> ");
	read(0, buffer, OOB_LEN);
}

void play()
{
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
