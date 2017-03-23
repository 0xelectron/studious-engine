#include<stdio.h>

struct fish 
{
	char *name;
	char *species;
	int teeth;	
	int age;
};

struct fish snappy = {"snappy","pirahna",69,4};

void catlog (struct fish f)
{
	printf("%s is a %s with %i teeth. He is %i. \n",f.name,f.species,f.teeth,f.age);
}

void label (struct fish f)
{
	printf("Name: %s.\nSpecies: %s.\nTeeth: %i. \nAge: %i. \n",f.name,f.species,f.teeth,f.age);
}






int main()
{
catlog(snappy);
label(snappy);
return 0;

}
