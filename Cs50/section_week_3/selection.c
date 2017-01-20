/**
 * selection.c
 *
 * week 3 section
 * fall 2013
 *
 * selection sort implementation
 */


#include<stdbool.h>
#include<stdio.h>
#include<cs50.h>
#include<stdlib.h>

void sort(int values[], int n);



const int MAX = 65536;

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./find needle\n");
        return -1;
    }

   

    // fill haystack
    int size;
    int haystack[MAX];
    for (size = 0; size < MAX; size++)
    {
        // wait for hay until EOF
        printf("\nhaystack[%d] = ", size);
        int straw = GetInt();
        if (straw == INT_MAX)
        {
            break;
        }
     
        // add hay to stack
        haystack[size] = straw;
    }
    printf("\n");

    // sort the haystack
    sort(haystack, size);
   
   for (int i=0; i<size;i++)
   {
    printf("%d : %d \n",i,haystack[i]);
   }
    
}


void sort(int values[], int n)
{
    // run the sort n times
    for (int i = 0; i < n; i++)
    {
        // remember the smallest value
        int smallest_index = i;
        
        // make comparisons throughout the rest of the list
        for (int j = i + 1; j < n; j++)
        {
            // find the smallest number
            if (values[j] < values[smallest_index])
            {
                smallest_index = j;
            }
        }
        
        // put the beginning of the list where the smallest number was
        int tmp = values[smallest_index];
        values[smallest_index] = values[i];

        // place it in the beginning of the list
        values[i] = tmp;
    }
}
