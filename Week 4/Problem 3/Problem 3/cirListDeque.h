/*********************************************************************
** Program Filename: cirListDeque.h
** Author: Given file
** Date: July 17, 2015
** Description: header file
** Input: none
** Output: none
*********************************************************************/

#ifndef CIRLISTDEQUE_H_INCLUDED
#define CIRLISTDEQUE_H_INCLUDED

# ifndef TYPE
# define TYPE      double
# define TYPE_SIZE sizeof(double)
# endif

# ifndef LT
# define LT(A, B) ((A) < (B))
# endif

# ifndef EQ
# define EQ(A, B) ((A) == (B))
# endif

/* struct prototype */
struct cirListDeque;

struct cirListDeque *createCirListDeque();

int isEmptyCirListDeque(struct cirListDeque *q);
void addBackCirListDeque(struct cirListDeque *q, TYPE val);
void addFrontCirListDeque(struct cirListDeque *q, TYPE val);
TYPE frontCirListDeque(struct cirListDeque *q);
TYPE backCirListDeque(struct cirListDeque *q);
void removeFrontCirListDeque(struct cirListDeque *q);
void removeBackCirListDeque(struct cirListDeque *q);
void freeCirListDeque(struct cirListDeque *q);

void printCirListDeque(struct cirListDeque *q);
void reverseCirListDeque(struct cirListDeque *q);

#endif // CIRLISTDEQUE_H_INCLUDED
