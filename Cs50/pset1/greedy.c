#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void)
{
    double f;
    int ans = 0;
    printf("O hai!");
    do
    {
        printf("How much Change is Owed?\n");
        f=GetFloat();
    }while(f < 0);
   
   f=f*100;
   f=round(f);
   
    while (f>=25) 
    {
        f = f-25;
        ans = ans + 1;
    }
     
    while (f >= 10)
    {
        f = f - 10;
        ans = ans + 1;
    }
    
    while (f >= 5 )
    {
        f = f - 5;
        ans = ans +1;
    }
     
    while(f >= 1)  
    {
        f = f - 1;
        ans = ans +1;
    }
     
  printf("%d\n",ans);     
        
       
}
