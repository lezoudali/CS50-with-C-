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
    if (n <= 0)
        return false;
        
    // TODO: implement a searching algorithm
    int beginning = 0;
    int ending    = n-1;
   
    
    while (ending >= beginning )
    {
        int middle = (ending + beginning)/2;
        if (value > values[middle])
        {
            beginning = middle +1;
        }
        else if(value< values[middle])
        {
            ending = middle-1;
        }
        else
            return true;
    }

    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    for (int i = 0; i < n ; i++)
    {
         for(int a = 0; a < n -1 ; a++)
            {
                if (values[a] > values[a+1])
                {
                    int temp = values[a];
                    values[a] = values[a+1];
                    values[a+1] = temp;
                }
                
            } 
    }
    return;
}
