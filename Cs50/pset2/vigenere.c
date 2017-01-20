#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>


int main(int argc, string argv[])
{
     //check for the correct arguments   
     if (argc != 2 )
        {
            printf("you need to enter only key.\n");
            return 1;
        }
    
    //check for correct keyword
    for(int t = 0,n = strlen(argv[1]);t < n; t++)
    {
    
        if(!(isalpha(argv[1][t])))
        {
            printf("please give me characters and not anything else!");
            return 1;
        }
   }
    
    string key = argv[1];
       
    string text = GetString();
    
    int l = strlen(key);
    
    
    
    //encypher each character at a time while maintaing the upper and lower cases.
        
    for(int i = 0,j = 0,n = strlen(text); i < n; i++,j++)
    {
        //convert the key to lower case
        
        key[j] = tolower(key[j]);
        
        if(isalpha(text[i]))
        {
                                
                if(isupper(text[i]))
                {
                    printf("%c",(((text[i] - 65)+ (key[j % l]-97))% 26) + 65);
                        
                }

                else if (islower(text[i]))
                {
                     printf("%c",(((text[i] - 97) + (key[j % l]-97))% 26) + 97);
                        
                }
            
            }

        else
        {
            printf("%c",text[i]);
            j--;
        }
    }
printf("\n");    
}
