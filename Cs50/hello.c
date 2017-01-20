#include<stdio.h>
#include<cs50.h>

int main(void)
{
    printf("Hi!,What's You Name: ");
    string name = GetString();
    printf("Hello, %s! \n", name);
}   
