#include<stdio.h>
#include<stdarg.h>

void print_arg(int arg,...)
{
	va_list ap;
	va_start (ap,arg);
	int i;
	for (i=0;i < arg; i++)
	{
		printf("argument: %i\n",va_arg(ap,int));
	}
va_end(ap);
}

int main()
{
print_arg(3,25,45,36);
return 0;
}
