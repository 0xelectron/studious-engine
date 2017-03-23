#include<stdio.h>
#include<math.h>
int main()
{
    char opera;

    float x,y,z;

    puts("Welcome to the simple c calculation program by Me:\n");

    puts("Enter the first value:\n");

    scanf("%f",&x);

    puts ("enter second value:\n");

    scanf("%f",&y);

    printf("Now enter your choice according to ur needs:\n hint:(Enter A for addition ,S for subtraction,M for multiplication and D for division):\n");

    scanf("%s", &opera);

    if (opera == 'A')
    {
        z = (x + y);
    }
    else if (opera == 'M')
    {
        z = (x*y);

    }
    else if (opera == 'D')
    {
        z = (x/y);

    }
    else if (opera == 'S')
    {
        z = (x-y);

    }
    else
        {
            puts("You have entered a Wrong choice");
        }
      printf("According to ur choice, ur result is %f", z);
return 0;
}
