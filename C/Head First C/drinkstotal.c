#include<stdio.h>
#include<stdarg.h>

enum drinks {
MUDSLIDE,FUZZY_NAVEL,MONKEY_GLAND,ZOMBIE
};

double price(enum drinks d)
{
switch(d)
{
	case MUDSLIDE:
		return 6.79;
	case FUZZY_NAVEL:
		return 5.31;
	case MONKEY_GLAND:
		return 4.82;
	case ZOMBIE:
		return 5.89;

}
return 0;
}


double total (int arg,...)
{
	double total = 0;
	va_list ap;
	va_start(ap,arg);
	int i=0;
	for (i=0;i<arg;i++)
	{
		enum drinks d = va_arg(ap,enum drinks);			
		total = total + price(d);
	}	
	va_end(ap);	
	return total;
}

int main()
{
printf("Price is %.2f \n",total(3,MONKEY_GLAND,FUZZY_NAVEL,ZOMBIE));
printf("price is %.2f \n",total(2,MONKEY_GLAND,FUZZY_NAVEL));


return 0;
}
