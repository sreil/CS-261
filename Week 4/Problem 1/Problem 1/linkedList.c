/*********************************************************************
** Program Filename: linkedList.c
** Author: Sean Reilly
** Date: July 19, 2015
** Description: Class for linked list
** Input:
** Output:
*********************************************************************/

#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


/* Double Link*/
struct DLink {
	TYPE value;
	struct DLink * next;
	struct DLink * prev;
};

/* Double Linked List with Head and Tail Sentinels  */

struct linkedList{
	int size;
	struct DLink *firstLink;
	struct DLink *lastLink;
};

/*
	initList
	param lst the linkedList
	pre: lst is not null
	post: lst size is 0
*/

void _initList (struct linkedList *lst) {
    assert(lst != NULL);
    lst->size = 0;
	struct DLink * first = malloc(sizeof(struct DLink));
    lst->firstLink = first;
	struct DLink * last = malloc(sizeof(struct DLink));
    lst->lastLink = last;
	last->value = 0;
	last->next = NULL;
	last->prev = lst->firstLink;
	first->value = 0;
	first->next = lst->lastLink;
	first->prev = NULL;
}

/*
 createList
 param: none
 pre: none
 post: firstLink and lastLink reference sentinels
 */

struct linkedList *createLinkedList()
{
	struct linkedList *newList = malloc(sizeof(struct linkedList));
	_initList(newList);
	return(newList);
}

/*
	_addLinkBeforeBefore
	param: lst the linkedList
	param: l the  link to add before
	param: v the value to add
	pre: lst is not null
	pre: l is not null
	post: lst is not empty
*/

/* Adds Before the provided link, l */

void _addLinkBefore(struct linkedList *lst, struct DLink *l, TYPE v)
{
    assert(lst != NULL&& l != NULL);
    struct DLink *add = (struct DLink *)malloc(sizeof(struct DLink));
    add->value = v;
    assert(add != NULL);
    struct DLink *temp = l->prev;
    l->prev = add;
    add->next = l;
    temp->next = add;
    add->prev = temp;
    lst->size++;

}


/*
	addFrontList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addFrontList(struct linkedList *lst, TYPE e)
{
    assert(lst != NULL);
    struct DLink * add = malloc(sizeof (struct DLink));
    add->value = e;
    assert(add != NULL);
    struct DLink *temp = lst->firstLink->next;
    lst->firstLink->next = add;
    add->prev = lst->firstLink;
    temp->prev= add;
    add->next = temp;
    lst->size++;

}

/*
	addBackList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addBackList(struct linkedList *lst, TYPE e) {
    assert(lst != NULL);
    struct DLink*add = malloc(sizeof (struct DLink));
    add->value = e;
    assert(add != NULL);
    struct DLink *temp = lst->lastLink->prev;
    lst->lastLink->prev = add;
    temp->next = add;
    add->prev = temp;
    add->next = lst->lastLink;
    lst->size++;
}

/*
	frontList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: none
*/

TYPE frontList (struct linkedList *lst) {
    assert(lst != NULL&& lst->size != 0);
    return lst->firstLink->next->value; //changed from return(1)
}

/*
	backList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: lst is not empty
*/

TYPE backList(struct linkedList *lst)
{
    assert(lst->size != 0 && lst != NULL);
	return lst->lastLink->prev->value; //changed from return(1)
}

/*
	_removeLink
	param: lst the linkedList
	param: l the linke to be removed
	pre: lst is not null
	pre: l is not null
	post: lst size is reduced by 1
*/

void _removeLink(struct linkedList *lst, struct DLink *l)
{
    assert(l != NULL && lst != NULL);
    l->prev->next = l->next;
    l->next->prev = l->prev;
    lst->size--;
        free(l);
}

/*
	removeFrontList
	param: lst the linkedList
	pre:lst is not null
	pre: lst is not empty
	post: size is reduced by 1
*/

void removeFrontList(struct linkedList *lst) {
    assert(lst != NULL);
    struct DLink *needMove = lst->firstLink->next;
    lst->firstLink->next = needMove->next;
    needMove->next->prev = lst->firstLink;
    lst->size--;

}

/*
	removeBackList
	param: lst the linkedList
	pre: lst is not null
	pre:lst is not empty
	post: size reduced by 1
*/

void removeBackList(struct linkedList *lst)
{
    assert(lst != NULL);
    struct DLink *needMove = lst ->lastLink->prev;
    lst->lastLink->prev = needMove->prev;
    needMove->prev->next= lst->lastLink;

}

/*
	isEmptyList
	param: lst the linkedList
	pre: lst is not null
	post: none
*/

int isEmptyList(struct linkedList *lst) {
    if (lst->size == 0)
        return 1;
    else
        return 0;

}


/* Function to print list
 Pre: lst is not null
 */
void _printList(struct linkedList* lst)
{
    assert(lst != NULL);
    struct DLink* current = lst->firstLink->next;
    do{
        printf("%d \n", current->value);
        current = current->next;
    } while (current!= lst->lastLink);

}

/*
	Add an item to the bag
	param: 	lst		pointer to the bag
	param: 	v		value to be added
	pre:	lst is not null
	post:	a link storing val is added to the bag
 */
void addList(struct linkedList *lst, TYPE v)
{
    assert(lst != NULL);
    addFrontList(lst, v);
}

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0
	param:	lst		pointer to the bag
	param:	e		the value to look for in the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	no changes to the bag
*/
int containsList (struct linkedList *lst, TYPE e) {
    assert(lst->size != 0 && lst != NULL);
    struct DLink* current = lst->firstLink->next;
    do{
        current = current->next;
    } while (!EQ(current->value, e)&& current!= lst->lastLink);
    if (current == lst->lastLink)
        return 0;
    else
	return 1;
}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs
	param:	lst		pointer to the bag
	param:	e		the value to be removed from the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	e has been removed
	post:	size of the bag is reduced by 1
*/
void removeList (struct linkedList *lst, TYPE e) {
    assert(lst != NULL && lst->size != 0);
    struct DLink* current = lst->firstLink;
    do{
        current = current->next;
    } while (!EQ(current->value, e) && current != lst->lastLink);
    if (current != lst->lastLink)
    {
        _removeLink(lst, current);
    }
}
