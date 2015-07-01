/*********************************************************************
** Program Filename: Q2.c
** Author: Sean Reilly
** Date: June 30, 2015
** Description: Sets a to twice it's orig value, b to half it's orig value, returns c
** Input: none
** Output: see description
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int *b, int c)
{
    *a = *a * 2; //double a

    *b = *b / 2; //half b

    c = *a + *b;
    return c; //returns c
}

int main()
{
    int x = 5, y = 6, z = 7;  //In the main function, declare three integers x,y, and z, and assign them values 5, 6, and 7

    printf("The value of x is: %d \n", x);
    printf("The value of y is: %d \n", y);
    printf("The value of z is: %d \n", z); // Print the values of x,y, and z

    foo(&x, &y, &z);

    printf("The value of x is now: %d \n", x);
    printf("The value of y is now: %d \n", y);
    printf("The value of z is now: %d \n", z);

    return 0;
}


/********************************************************************
 Is the return value different than the value of z? Why?

 Yes because you are modifying a copy of z
*********************************************************************/
