#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "util.h"

#define NAME_LEN 0x40
#define BUF_LEN 0x100
char fname[NAME_LEN];

void init()
{
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
	setvbuf(stderr, 0, 2, 0);
}

void gift()
{
        __asm__ __volatile__(
                "ldr x0, [x19] ; ldp x19, x20, [sp, #0x10] ; ldp x29, x30, [sp], #0x20 ; ret;"
                "ldr x17, [sp, #0x10] ; ldr x17, [x17]; add x17, x17, #4 ; br x17; "
        );
}

void open_file()
{
        puts("Input file name:");
        read(0, fname, NAME_LEN);
        puts("No open this time");
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
        puts("No No No");
}

void menu()
{
        puts("1. Open file");
        puts("2. Read flag");
        puts("3. Play game");
        puts("4. Close file");
        puts("5. Exit");
        puts("Choice >> ");
}

int main()
{
        int choice, flag = 1;

        init();
        print_desc();

        while (flag) {
                /* code */
                menu();
                scanf("%d", &choice);
                switch ( choice )
                {
                case 1:
                        open_file();
                        break;
                case 2:
                        read_flag();
                        break;
                case 3:
                        play_game();
                        break;
                case 4:
                        close_file();
                        break;
                case 5:
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