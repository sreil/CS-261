/*********************************************************************
** Program Filename: calc.c
** Author: Sean Reilly, given file
** Date: July 7, 2015
** Description:  Various calculations
** Input: none
** Output: Prints calcs
*********************************************************************/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "dynamicArray.h"

/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
*/

#define PI 3.14159

int isNumber(char *s, double *num)
{
	char *end;
	double returnNum;

	if(strcmp(s, "0") == 0)
	{
		*num = 0;
		return 1;
	}
	else
	{
		returnNum = strtod(s, &end);
		/* If there's anything in end, it's bad */
		if((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;
			return 1;
		}
	}
	return 0;  //if got here, it was not a number
}

void printInvalid(struct DynArr *stack, char* op)
{
	int size, i;

	if (isEmptyDynArr(stack) == 0)
		size = sizeDynArr(stack);
	else
		size = 0;


	printf("Invalid calculation string: ");
	for (i = 0; i < size; i++)
	{
		printf("%f ", getDynArr(stack, i));
	}
	printf("%s\n", op);
	deleteDynArr(stack);
	exit(1);

}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	their sum is pushed back onto the stack.
*/
void add (struct DynArr *stack)
{
	double i = topDynArr(stack);
	popDynArr(stack);
	double j = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, (i + j));
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{
	double i = topDynArr(stack);
	popDynArr(stack);
	double j = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, (j - i));
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
	double i = topDynArr(stack);
	popDynArr(stack);
	double j = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, (j / i));
}

void multiply(struct DynArr *stack)
{
	double i = topDynArr(stack);
	popDynArr(stack);
	double j = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, (i * j));
}

void power(struct DynArr *stack)
{
	double i = topDynArr(stack);
	popDynArr(stack);
	double j = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, pow(j, i));
}

void square(struct DynArr *stack)
{
	double i = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, pow(i, 2));
}

void cube(struct DynArr *stack)
{
	double i = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, pow(i, 3));
}

void abs_val(struct DynArr *stack)
{
	double i = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, fabs(i));
}

void square_root(struct DynArr *stack)
{
	double i = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, sqrt(i));
}

void exponential(struct DynArr *stack)
{
	double i = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, exp(i));
}

void natural_log(struct DynArr *stack)
{
	double i = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, log(i));
}

void base_10_log(struct DynArr *stack)
{
	double i = topDynArr(stack);
	popDynArr(stack);

	pushDynArr(stack, log10(i));
}

double calculate(int numInputTokens, char **inputString)
{
	int i;
	double result = 0.0;
	char *s;
	struct DynArr *stack;

	//set up the stack
	stack = createDynArr(20);

	for(i=1;i < numInputTokens;i++)
	{
		s = inputString[i];

		// Hint: General algorithm:
		// (1) Check if the string s is in the list of operators.
		//   (1a) If it is, perform corresponding operations.
		//   (1b) Otherwise, check if s is a number.
		//     (1b - I) If s is not a number, produce an error.
		//     (1b - II) If s is a number, push it onto the stack

		if (strcmp(s, "+") == 0)
		{
			if (isEmptyDynArr(stack) == 0 && sizeDynArr(stack) >= 2)
				add(stack);
			else
				printInvalid(stack, "+");
		}
		else if (strcmp(s, "-") == 0)
		{
			if (isEmptyDynArr(stack) == 0 && sizeDynArr(stack) >= 2)
				subtract(stack);
			else
				printInvalid(stack, "-");
		}

		else if (strcmp(s, "/") == 0)
		{
			if (isEmptyDynArr(stack) == 0 && sizeDynArr(stack) >= 2)
				divide(stack);
			else
				printInvalid(stack, "/");
		}
		else if (strcmp(s, "x") == 0)
		{
			if (isEmptyDynArr(stack) == 0 && sizeDynArr(stack) >= 2)
				multiply(stack);
			else
				printInvalid(stack, "x");
		}
		else if (strcmp(s, "^") == 0)
		{

			if (isEmptyDynArr(stack) == 0 && sizeDynArr(stack) >= 2)
				power(stack);
			else
				printInvalid(stack, "^");
		}
		else if (strcmp(s, "^2") == 0)
		{
			if (isEmptyDynArr(stack) == 0 && sizeDynArr(stack) >= 1)
				square(stack);
			else
				printInvalid(stack, "^2");
		}
		else if (strcmp(s, "^3") == 0)
		{
			if (isEmptyDynArr(stack) == 0 && sizeDynArr(stack) >= 1)
				cube(stack);
			else
				printInvalid(stack, "^3");
		}
		else if (strcmp(s, "abs") == 0)
		{
			if (isEmptyDynArr(stack) == 0 && sizeDynArr(stack) >= 1)
				abs_val(stack);
			else
				printInvalid(stack, "abs");
		}
		else if (strcmp(s, "sqrt") == 0)
		{
			if (isEmptyDynArr(stack) == 0 && sizeDynArr(stack) >= 1)
				square_root(stack);
			else
				printInvalid(stack, "sqrt");
		}
		else if (strcmp(s, "exp") == 0)
		{
			if (isEmptyDynArr(stack) == 0 && sizeDynArr(stack) >= 1)
				exponential(stack);
			else
				printInvalid(stack, "exp");
		}
		else if (strcmp(s, "ln") == 0)
		{
			if (isEmptyDynArr(stack) == 0 && sizeDynArr(stack) >= 1)
				natural_log(stack);
			else
				printInvalid(stack, "ln");
		}
		else if (strcmp(s, "log") == 0)
		{
			if (isEmptyDynArr(stack) == 0 && sizeDynArr(stack) >= 1)
				base_10_log(stack);
			else
				printInvalid(stack, "log");
		}
		else
		{
			// FIXME: You need to develop the code here (when s is not an operator)
			// Remember to deal with special values ("pi" and "e")
			if(strcmp(s, "pi") == 0)
			{
				pushDynArr(stack, PI);

			}
			else if(strcmp(s, "e") == 0)
			{
				pushDynArr(stack, exp(1.0));
			}
			else
			{
				double number;
				if(isNumber(s, &number) == 1)
				{
					pushDynArr(stack, number);
				}
				else
				{
					printf("Number is invalid %s\n", s);
				}
			}
		}
	}

	/* FIXME: You will write this part of the function (2 steps below)
	 * (1) Check if everything looks OK and produce an error if needed.
	 * (2) Store the final value in result and print it out.
	 */
	result = topDynArr(stack);
	popDynArr(stack);

	int finalStackSize = sizeDynArr(stack);

	if (finalStackSize != 0)
	{
		printf("Sorry, but the following items were left on calculation stack: ");

		for (i = 0; i < finalStackSize; i++)
			printf("%f ", getDynArr(stack, i));

		printf("Missing an operator?\n");
		deleteDynArr(stack);
	}

	printf("The result is %f\n", result);

	//clean up the memory that we used
	deleteDynArr(stack);

	return result;
}

int main(int argc , char** argv)
{
	// assume each argument is contained in the argv array
	// argc-1 determines the number of operands + operators
	if (argc == 1)
		return 0;

	calculate(argc,argv);

	return 0;
}
