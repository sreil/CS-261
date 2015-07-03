/*********************************************************************
** Program Filename: Q4.c
** Author: Sean Reilly
** Date: July 1, 2015
** Description: Modifies Q1
** Input: none
** Output: alternating upper and lowercase letters
*********************************************************************/


#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n) // The function prototype is void sort(struct student* students, int n).
{
    if(n == 0)
        return;

    int i, j;
    struct student temp;
    for (i = n - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (students[j].score > students[j + 1].score)
            {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}


int main()
{

    struct student *students = malloc(10*(sizeof(struct student)));

    return 0;
}
