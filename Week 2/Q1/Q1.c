/*********************************************************************
** Program Filename: Q1.c
** Author: Sean Reilly
** Date: June 29, 2015
** Description:  add here
** Input: none
** Output: add here
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct student {
    int id;
    int score;
};

struct student* allocate() //Write a function struct student* allocate() that allocates memory for ten students and returns the pointer.
{
     struct student *stud = (struct student *) malloc(10*(sizeof(struct student)));

     return stud;
};
void generate(struct student* students) //Write a function void generate(struct student* students) that generates random IDs and scores for
                                        //each of the ten students and stores them in the array of students
{
    int i;
    printf("ID's are as follows: \n");
    for(i = 0; i < 10; i++){
        students[i].id = ((rand() % 10) + 1);
        students[i].score = ((rand() % 100) + 1);
    }
}
void output(struct student* students) //Write a function void output(struct student* students) that prints the ids and scores of all the students.
{
    int i;
    for(i = 0; i < 10; i++){
        printf("ID: %d Score: %d \n",students[i].id, students[i].score);
    }
}

void summary(struct student* students) //Write a function void summary(struct student* students) that prints the minimum score, maximum score and average score of the ten students.
{
     int i, j = 0, sum = 0;
     int avg, min, max;

     for(i = 0; i < 10; i++)
        {
            sum += students[i].score;
        }
        avg = sum / 10;

     min = students[0].score;

     for(i = 0; i < 10; i++)
     {
         if(students[i].score < min)
         {
             min = students[i].score;
         }
     }

     max = students[0].score;

      for(i = 0; i < 10; i++)
     {
         if(students[i].score > max)
         {
             max = students[i].score;
         }
     }

     printf("The minimum score %d, the maximum score is %d, and the average score is %d \n", min, max, avg);
}

void deallocate(struct student* stud) //Write a function void deallocate(struct student* stud) that frees the memory allocated to students.
{
     free(stud);
}

int main()
{
    srand(time(NULL));
    struct student *st = 0;

    st = allocate();
    generate(st);
    output(st);
    summary(st);
    deallocate(st);

    return 0;
}
