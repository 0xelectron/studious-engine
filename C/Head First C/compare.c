#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int compare_scores_desc(const void* score_a,const void* score_b)
{
	int a = *(int*)score_a;
	int b = *(int*)score_b;
	return b-a;
}

int compare_names(const void* name_a,const void* name_b)
{
	char** a = (char**)name_a;
	char** b = (char**)name_b;
	return strcmp(*a,*b);
}

int main()
{
	int scores[] = {543,323,32,554,11,3,112};
	int i;
	qsort(scores,7,sizeof(int),compare_scores_desc);
	puts("These are the scores:");
	puts("---------------------------------------------------");	
	for (i=0;i<7;i++)
	{
		printf("Score = %i\n",scores[i]);		
	
	}
	
	puts("---------------------------------------------------");	
	char *names[] = {"Karen","Mark","Brett","Molly"};
	qsort(names,4,sizeof(char*),compare_names);
	puts("These are the names:");
	puts("---------------------------------------------------");	
	for (i=0;i<4;i++)
	{
		printf("%s \n",names[i]);
	}
	puts("---------------------------------------------------");	
	return 0;

}
