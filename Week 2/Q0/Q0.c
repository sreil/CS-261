/*********************************************************************
** Program Filename: Q0.c
** Author: Sean Reilly
** Date: June 28, 2015
** Description:  Print value of x
** Input: none
** Output: Prints value of x
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

void fooA(int *iptr) //In fooA(int * iptr), print the value of the integer pointed to by iptr, the address pointed to by iptr, and the address of iptr itself.
{
    printf("The value of the integer pointed to by iptr is: %d \n", *iptr);
    printf("The address pointed to by iptr is: %p \n", iptr);
    printf("iptr's address is: %p \n", &iptr);
}

int main()
{
    int x = 14;
    printf("Address of x is: %p\n", &x); //In the main function, declare an integer, x. Print the address of x (using the address of operator).

    fooA(&x); //Pass x as an argument to a function void fooA(int* iptr).

    printf("Value of x is: %d\n", x); //In the main function, following the call to fooA(...), print the value of x.

    return 0;
}
