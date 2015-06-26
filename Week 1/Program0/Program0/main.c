#include <stdlib.h>

int main()
{
	int number;
	
	printf("Please enter a number and I will check if it is odd or even: ");
	scanf("%d", &number);
	
	if ((number % 2) == 0)      
		printf("%d is even.", number);
	else
		
		printf("%d is odd.", number);
	return 0;
}