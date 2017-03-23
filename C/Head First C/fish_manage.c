#include<stdio.h>

struct exercise
{
	const char *description;
	float duration;
};

struct meal
{
	const char *ingredients;
	float weight;
};

struct prefrences
{
	struct meal food;	
	struct exercise exercise1;
	
};

struct fish 
{
	const char *name;
	const char *species;
	int teeth;
	int age;
	struct prefrences care;
};

struct fish snappy = {"snappy","pirahna",64,5,{{"playing",2},{"fish",25}}};


void label(struct fish f)
{
	printf("Name: %s\nspecies:%s\nFood ingredients:%s\nFood weight:%f\nExercise description:%s\n,Exercise duration:%f\n",f.name,f.species,f.care.food.ingredients,f.care.food.weight,f.care.exercise1.description,f.care.exercise1.duration);
}

int main()
{
	label(snappy);	
	return 0;
}
