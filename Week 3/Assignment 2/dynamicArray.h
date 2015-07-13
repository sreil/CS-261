/*********************************************************************
** Program Filename: dynamicArray.c
** Author: Sean Reilly, given file
** Date: July 8, 2015
** Description:  Various calculations
** Input: none
** Output: Prints calcs
*********************************************************************/

#include<math.h>

#ifndef DYNAMIC_ARRAY_INCLUDED
#define DYNAMIC_ARRAY_INCLUDED 1


# ifndef TYPE
# define TYPE     double
# define TYPE_SIZE sizeof(double)
# endif

# ifndef EQ
# define EQ(A, B) (fabs(A - B) < 10e-7)
# endif

typedef struct DynArr DynArr;
DynArr *createDynArr(int cap);
void deleteDynArr(DynArr *v);
int sizeDynArr(DynArr *v);
void addDynArr(DynArr *v, TYPE val);
TYPE getDynArr(DynArr *v, int pos);
void putDynArr(DynArr *v, int pos, TYPE val);
void swapDynArr(DynArr *v, int i, int  j);
void removeAtDynArr(DynArr *v, int idx);
int isEmptyDynArr(DynArr *v);
void pushDynArr(DynArr *v, TYPE val);
TYPE topDynArr(DynArr *v);
void popDynArr(DynArr *v);
int containsDynArr(DynArr *v, TYPE val);
void removeDynArr(DynArr *v, TYPE val);

#endif // DYNAMICARRAY_H_INCLUDED
