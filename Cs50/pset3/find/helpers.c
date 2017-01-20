/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // binary search: implement a searching algorithm
   if(value < 0)
   {
        return false;
   }
  
    int begining = 0;
    int end = n - 1;
    
   //go through the list
    while(begining <= end)
    {
        int middle = (begining + end)/2;
        //check if value is in middle
        if ( value == values[middle])
        {
            return true;
        }
        //else check if value is less than middle
        else if (values[middle]>value)
        {
            end = middle - 1;
        }
        //else check if value is greater  than middle
        else
        {
            begining = middle + 1;
        }
    }

   
   
   return false;
}

/**
 * Sorts array of n values.
 */
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
