/*********************************************************************
** Program Filename: Q3.c
** Author: Sean Reilly
** Date: July 1, 2015
** Description: Sorts a given array in ascending order
** Input: none
** Output: Sorts a given array in ascending order
*********************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int* numbers, int n)
{
    if(n == 0)
        return;

    int i, j, temp;
    for (i = n - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (numbers[j] > numbers[j + 1])  // values out of order, so swap
            {
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n = 20, i; //In the main function, declare an integer n and assign it a value of 20.

    int *numbers = malloc(n * sizeof(int)); //Allocate memory for an array of n integers using malloc.

    srand(time(NULL)); //random numbers

    for (i = 0; i < n; i++)
    {
        numbers[i] = rand() % 100;  // Fill this array with random numbers, using the c math library random number generator rand()
    }

    printf("Unsorted numbers; \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", numbers[i]); // Print the contents of the array.
    }

    sort(numbers, n); //Pass this array along with n to the sort(...) function above.

    printf("\n\nSorted numbers; \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", numbers[i]); //Print the contents of the sorted array following the call to sort(...).
    }

    return 0;
}
