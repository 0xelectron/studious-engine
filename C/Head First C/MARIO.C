#include<stdio.h>
int main()
{
    int n;
    do
    {
        printf("Enter the Height of the Pyramid:");
        scanf("%i",&n);

    }
    while(n <= 0 || n > 23);

    int i,j,k;
    for (i=0;i<n;i++)
    {
        for(k=0; k < n-i ; k++)
            printf(" ");
        for (j = 0; j < i+2; j++)
            printf("#");

        printf("\n");
    }



}
