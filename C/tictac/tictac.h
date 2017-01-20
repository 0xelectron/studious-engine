#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<ctype.h>
#include<string.h>
#include<unistd.h>

int AIMODE;
char BOARD[3][3];
char TIC, CTIC;
FILE *f;

void usage(const char *p);
void init(void);
void greet(void);
void asktic(void);
unsigned takeinput(void);
int won(void);
int gameover(void);
void save(FILE *f);
void clear(void);
int move(unsigned m);
void cpumove(void);
void draw(void);
void aimode(void);
void t_log(FILE *f, const char *fmt, void *args);
void fatal(const char *fmt, ...);
