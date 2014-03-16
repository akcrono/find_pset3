/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
 //recursive search function
bool search(int value, int values[], int n)
{
    if (n==1)       //checks for single value, returns true for match, false for no match
    {
        if (value==values[0])
            return true;
        else
            return false;
    }
    if (value<values[n/2]) //if there is more than 1 value, divide in half, call search function with new half
    {
        int temp[n/2];
        
        for (int i=0;i<n/2;i++)
            temp[i]=values[i];    
            
        return search(value, temp, n/2);

    }   
    else if (value>values[n/2])
    {           
        int temp[n-(n/2)];

        for (int i=0;i<n-n/2;i++)
            temp[i]=values[i+n/2];    
            
        return search(value, temp, n-(n/2));

    }
    else    //if value[n/2] number happens to match search value
    {
        return true;
    }
        
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{

    for (int i=0; i<n; i++)
    {
        int vLow = i;
        for (int j=i+1; j<n; j++)
            if (values[j]<values[vLow])           
                vLow=j;               
        if (vLow != i)
        {
            int tempSwap = values[vLow];  //swap values of values[i] and values[vLow] if not the same
            values[vLow] = values[i];
            values[i] = tempSwap; 
        }  

    } 
    return;
}
