#include<cs50.h>
#include<stdio.h>

int main(void)
{
    int n;
    do
    {
        printf("Height: ");
        n=GetInt();
    }while(n < 0 || n > 23);
    
    for(int i = 0;i < n; i++)
    {
        for(int j = 1; j < n-i; j++)
        {
            printf(" ");
        }    
        for(int k = 0; k < i+2; k++)
        {
            printf("#");
        }
      printf("\n");  
    }
}
