#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


int main(int argc, char* argv[])
{
        
    //check for the correct arguments
    if (argc != 2)
    {
        printf("you need to enter only key.\n");
        return 1;
    }
    
    int k = atoi(argv[1]);
       
    string pt = GetString();
    
    //encypher each character at a time while maintaing the upper and lower cases.
    for(int i = 0,n = strlen(pt); i < n; i++)
    {
        if(isalpha(pt[i]))
        {
            if(isupper(pt[i]))
            {
                printf("%c",((pt[i] - 65 )+ k)% 26 + 65);
            }
        
            else if (islower(pt[i]))
            {
                printf("%c",((pt[i] - 97) + k)% 26 + 97);
            }
           
        }
        
        else
        {
            printf("%c",pt[i]);
        }
    }
    printf("\n");   
}
