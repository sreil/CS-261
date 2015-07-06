/*********************************************************************
** Program Filename: Q5.c
** Author: Sean Reilly
** Date: July 1, 2015
** Description: Converts a string into alternating upper and lowercase letters
** Input: user inputs string
** Output: alternating upper and lowercase letters
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //for toupper and tolower

const int max = 500; //maximum amount of characters allowed

 void sticky(char* word)
 {
     int i;

     for(i = 0; i < max; i++)
     {
         if(word[i] == '\0') //Watch out for the end of the string, which is denoted by ‘\0’
                    return;
         if(i % 2)
            word[i] = tolower(word[i]); //sticky() should modify the word to appear with “sticky caps” (http://en.wikipedia.org/wiki/StudlyCaps) , that
                                        //is, the letters must be in alternating cases(upper and lower)
         else
            word[i] = toupper(word[i]);
     }
 }

int main()
{
    printf("Please enter a word: ");

    char convert[max];
    scanf("%s", convert);
    sticky(convert);
    printf("%s", convert);
    return 0;
}
