#include<stdio.h>
int main()
{
float f;
float c;
for(c = 300;c <= 300 && c>= 0;c = c - 20)
{

printf("celcius:%.1f	farenhiet:%2.1f\n",c,(9.0/5.0)*c + 32);
}
return 0;
}
