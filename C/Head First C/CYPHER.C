#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int main(int argc,char *argv[])
{
        if(argc != 2)
        {


            printf("you need to enter only key");
            return 1;
        }
int key = atoi(argv[1]);
char text[255];

//ask user for the text
printf("Enter the string to cypher:");
fgets(text,255,stdin);
int i;
int n = strlen(text);
for (i=0;i<n;i++)
{
    if(isalpha(text[i]))
    {
        if(isupper(text[i]))
            printf("%c",((text[i]-64 + key)% 26 )+64 );
        if(islower(text[i]))
            printf("%c",((text[i-64 + key])% 26)+64);


    }

    if(!isalpha(text[i]))
        printf("%c",text[i]);
}




}
