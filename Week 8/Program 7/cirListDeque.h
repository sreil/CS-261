#ifndef __CIRLISTDEQUE_H
#define __CIRLISTDEQUE_H

#include "type.h"

/* Double Link Struture */
struct DLink {
  TYPE value;			/* value of the link */
  struct DLink * next;	/* pointer to the next link */
  struct DLink * prev;	/* pointer to the previous link */
};

/* Deque Structure based on Circularly-Doubly-Linked List */
struct cirListDeque {
  int size;				/* number of links in the deque */
  struct DLink *last; 	/* pointer to the last link */
};
typedef struct cirListDeque cirListDeque;

void initCirListDeque(struct cirListDeque *q);

int isEmptyCirListDeque(struct cirListDeque *q);
void addBackCirListDeque(struct cirListDeque *q, TYPE val);
void addFrontCirListDeque(struct cirListDeque *q, TYPE val);
TYPE frontCirListDeque(struct cirListDeque *q);
TYPE backCirListDeque(struct cirListDeque *q);
void removeFrontCirListDeque(struct cirListDeque *q);
void removeBackCirListDeque(struct cirListDeque *q);
void removeAllCirListDeque(struct cirListDeque *q);

void printCirListDeque(struct cirListDeque *q);

#endif
