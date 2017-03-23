#include<stdio.h>
#include<math.h>

int main()
{
    int mon,counter;
    counter = 0;
    do
    {
        printf("Enter the amount:");
        scanf("%d",&mon);

    }
    while(mon < 0 || mon > 100);
    printf("amount:%d\n",mon);
    while(mon >= 25)
    {
        counter++;
        mon = mon-25;
    }
    while (mon >= 10)
    {
            counter++;
            mon = mon - 25;
        }
    while (mon >= 5)
        {
            counter++;
            mon= mon-5;

        }
    while (mon >= 1)
        {
            counter++;
            mon = mon-1;
        }
    printf("Coins:%d\n",counter);

return 0;
}
