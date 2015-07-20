#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED


# ifndef TYPE
# define TYPE      int
# define TYPE_SIZE sizeof(int)
# endif
# ifndef LT
# define LT(A, B) ((A) < (B))
# endif

# ifndef EQ
# define EQ(A, B) ((A) == (B))
# endif

struct linkedList;

struct linkedList *createLinkedList();

/* Deque Interface */
int 	isEmptyList(struct linkedList *lst);
void  addBackList(struct linkedList *lst, TYPE val);
void 	addFrontList(struct linkedList *lst, TYPE val);

TYPE  frontList(struct linkedList *lst);
TYPE 	backList(struct linkedList *lst);

void  removeFrontList(struct linkedList *lst);
void 	removeBackList(struct linkedList *lst);

/*Bag Interface */
void addList(struct linkedList *lst, TYPE val);
int containsList(struct linkedList *lst, TYPE val);
void removeList(struct linkedList *lst, TYPE val);

#endif // LINKEDLIST_H_INCLUDED
