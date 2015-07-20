/*********************************************************************
** Program Filename: linkedListMain.c
** Author: Given file
** Date: July 20, 2015
** Description: Linked lists
** Input:
** Output:
*********************************************************************/


#include "linkedList.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*Function to get number of milliseconds elapsed since program started execution*/
double getMilliseconds() {
   return 1000.0 * clock() / CLOCKS_PER_SEC;
}

int main(int argc, char* argv[]){
	struct linkedList* b;
	int n, i;
	double t1, t2;

	#ifdef MEMORY_TEST_INCLUDED
	/* variables to hold memory used before and after creating LinkedList */
	long m1, m2;
	/* memory used BEFORE creating LinkedList */
	m1 = getMemoryUsage();
	#endif

	if( argc != 2 ) return 0;


	//n = atoi(argv[1]);/*number of elements to add*/
	int index = atoi(argv[1]);
	for (n = index; n <= 256000; n=n*2)
	{
		b = createLinkedList();
		for( i = 0 ; i < n; i++) {
			addList(b, (TYPE)i);/*Add elements*/
		}

		#ifdef MEMORY_TEST_INCLUDED
		/* memory used AFTER creating LinkedList */
		m2 = getMemoryUsage();
		printf("Memory used by LinkedList: %ld KB \n", m2-m1);
		#endif

		t1 = getMilliseconds();/*Time before contains()*/

		for(i=0; i<n; i++) {
			containsList(b, i);
		}

		t2 = getMilliseconds();/*Time after contains()*/
		printf("Time for running contains() on %d elements: %g ms\n", n, t2-t1);

		/* delete the linked list */
		//deleteLinkedList(b);
	}

	return 0;
}
