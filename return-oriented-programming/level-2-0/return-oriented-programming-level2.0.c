#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "util.h"

#define NAME_LEN 0x20
#define BUF_LEN 0x100
char gift[] = "/bin/cat\0/flag\0";
int fd;
char fname[NAME_LEN];

int read_int()
{
	char buf[0x10];
	read(0, buf, 0x10);
	return atoi(buf);
}

void list_dir()
{
	char *list_argv[] = {".", ".", NULL};

        if (fork() == 0) {
                // child
                execv("/bin/ls", list_argv);
                exit(0);
        }
        else {
                // parent
                wait(NULL);
        }
}

void open_file()
{
        puts("Input file name:");
        fgets(fname, NAME_LEN, stdin);
        fd = open(fname, 0);
	if (fd < 0) {
		printf("无法打开文件\n");
		return;
	}
}

void read_flag()
{
        puts("No No No");
}

void leave_message()
{
        char message[0x30];
        puts("Input your message:");
        read(0, message, BUF_LEN); 
}

void play_game()
{
        leave_message();
}

void close_file()
{
        if (fd < 0) {
		printf("文件未打开\n");
		return;
	}
        close(fd);
}

void init()
{
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
	setvbuf(stderr, 0, 2, 0);
}

void menu()
{
        puts("1. List dir");
        puts("2. Open file");
        puts("3. Read flag");
        puts("4. Play game");
        puts("5. Close file");
        puts("6. Exit");
        puts("Choice >> ");
}

int main()
{
        int flag = 1;

        init();
        print_desc();

        while (flag) {
                /* code */
                menu();
                switch (read_int())
                {
                case 1:
                        list_dir();
                        break;
                case 2:
                        open_file();
                        break;
                case 3:
                        read_flag();
                        break;
                case 4:
                        play_game();
                        break;                        
                case 5:
                        close_file();
                        break;
                case 6:
                        flag = 0;
                        break;
                default:
                        puts("Invalid choice");
                        break;
                }
        }
        
        print_exit();

	return 0;
}