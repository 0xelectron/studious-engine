#include<stdio.h>
#include<unistd.h>

int
main ()
{
	printf("hello world!\n");
	usleep(500000);
	printf("\033[2J");
	printf("\033[%d;%dH", 0, 0);
	usleep(500000);
	printf("hello buddy!\n");
}
