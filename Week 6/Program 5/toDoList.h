/*********************************************************************
** Program Filename: toDoList.h
** Author: Given file
** Date: July 30, 2015
** Description: header for toDoList
** Input: none
** Output:
*********************************************************************/


#ifndef __TODOLIST_H
#define __TODOLIST_H

#include "dynamicArray.h"
#include "type.h"

Task* createTask (int priority, char *desc);

void saveList(DynArr *heap, FILE *filePtr);

void loadList(DynArr *heap, FILE *filePtr);

void printList(DynArr *heap);

void deleteList(DynArr *heap);

#endif
