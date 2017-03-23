#include<stdio.h>
#define OUT 0
#define IN 1

main()
{
int c,nw,nc,nl,state;
state = OUT;
nl=nw=nc=0;
while((c = getchar()) != EOF)
{
++nc;

if ( c == '\n')
++nl;
		
if (c == '\n' || c == ' ' || c== '\t') 
state = OUT;
else if (state = OUT) 
{
state = IN;
++nw;
}

}
printf("%d %d %d",nl,nw,nc);

}
