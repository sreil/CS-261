/*********************************************************************
** Program Filename: Q4.c
** Author: Sean Reilly
** Date: July 1, 2015
** Description: Modifies Q1/Q3
** Input: none
** Output: prints ID's and sorts scores in ascending order
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n)
{
	int i, j;
	struct student temp;

	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (students[j + 1].score < students[j].score)     //Modify the above sort(...) function from Q.3 to sort an array of n students based on their scores in ascending order
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
	int n = 20, i;  //used int of 20 again

	struct student *students = malloc(sizeof(struct student)*n); //modified from Q3

    srand(time(NULL)); //random numbers and ID's

    for(i = 0; i < n; i++)
    {
        students[i].id = i+1;
    }

    for(i = 0; i < n; i++)
    {
        students[i].score = rand()%101; //for scores, random goes to 100
    }
    sort(students, n);

    printf("Sorted ID's and scores are as follows:\n");

    for(i = 0; i < n; i++)
	{
        printf("ID: %d \t\tScore: %d\n", students[i].id, students[i].score);
    }

    return 0;
}
