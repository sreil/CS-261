/*********************************************************************
** Program Filename: hashMap.c
** Author: Given file/Sean Reilly
** Date: August 8, 2015
** Description: hashing functions
** Input: none
** Output:
*********************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "hashMap.h"



/*the first hashing function you can use*/
int stringHash1(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += str[i];
	return r;
}

/*the second hashing function you can use*/
int stringHash2(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += (i+1) * str[i]; /*the difference between stringHash1 and stringHash2 is on this line*/
	return r;
}

/* initialize the supplied hashMap struct*/
void _initMap (struct hashMap * ht, int tableSize)
{
	int index;
	if(ht == NULL)
		return;
	ht->table = (hashLink**)malloc(sizeof(hashLink*) * tableSize);
	ht->tableSize = tableSize;
	ht->count = 0;
	for(index = 0; index < tableSize; index++)
		ht->table[index] = NULL;
}

/* allocate memory and initialize a hash map*/
hashMap *createMap(int tableSize) {
	assert(tableSize > 0);
	hashMap *ht;
	ht = malloc(sizeof(hashMap));
	assert(ht != 0);
	_initMap(ht, tableSize);
	return ht;
}

/*
 Free all memory used by the buckets.
 Note: Before freeing up a hashLink, free the memory occupied by key and value
 */
void _freeMap (struct hashMap * ht)
{
	/*write this*/
	struct hashLink *next, *current;

    for(int i = 0; i < ht -> tableSize; i++)
    {
        current = ht -> table[i];

        while(current != 0)
        {
            next = current -> next;

            free(current);

            current = next;
        }

        ht -> table[i] = 0;
    }

    free(ht -> table);

    ht -> tableSize = 0;

    ht -> count = 0;
}

/* Deallocate buckets and the hash map.*/
void deleteMap(hashMap *ht) {
	assert(ht!= 0);
	/* Free all memory used by the buckets */
	_freeMap(ht);
	/* free the hashMap struct */
	free(ht);
}

/*
Resizes the hash table to be the size newTableSize
*/
void _setTableSize(struct hashMap * ht, int newTableSize)
{
    struct hashLink *last, *current;

    _initMap(ht, newTableSize);

    for (int i = 0; i < ht -> tableSize; i++)
    {
        current = ht -> table[i];

        while(current != 0)
        {

	   	    insertMap(ht, current -> key, current -> value);

	   	    last = current;

	   	    current = current -> next;

	   	    free(last);
	   	}
    }
}

/*
 insert the following values into a hashLink, you must create this hashLink but
 only after you confirm that this key does not already exist in the table. For example, you
 cannot have two hashLinks for the word "taco".

 if a hashLink already exists in the table for the key provided you should
 replace that hashLink--this requires freeing up the old memory pointed by hashLink->value
 and then pointing hashLink->value to value v.

 also, you must monitor the load factor and resize when the load factor is greater than
 or equal LOAD_FACTOR_THRESHOLD (defined in hashMap.h).
 */
void insertMap (struct hashMap * ht, KeyType k, ValueType v)
{
    int index;

    if(tableLoad(ht) >= LOAD_FACTOR_THRESHOLD)
    {
        _setTableSize(ht, (2 * ht -> tableSize));
    }

    struct hashLink *link = malloc(sizeof(struct hashLink));

    index = stringHash2(k) % ht -> tableSize;

    if(index < 0)
    {
        index += ht -> tableSize;
    }

    assert(link);
    link -> next = 0;
    link -> key = k;
    link -> value = v;

    if(containsKey(ht, k))
    {
        removeKey(ht, k);
    }

    if(!ht -> table[index])
    {
        ht -> table[index] = link;
    }
    else
    {
        struct hashLink *current = ht -> table[index];

        while(current -> next)
        {
            current = current -> next;
        }
        current -> next = link;
    }

    ht -> count++;
}

/*
 this returns the value (which is void*) stored in a hashLink specified by the key k.

 if the user supplies the key "taco" you should find taco in the hashTable, then
 return the value member of the hashLink that represents taco.

 if the supplied key is not in the hashtable return NULL.
 */
ValueType* atMap (struct hashMap * ht, KeyType k)
{
    int index;
    index = stringHash2(k) % ht -> tableSize;

    if(index < 0)
    {
        index += ht -> tableSize;
    }

    struct hashLink *current = ht -> table[index];

    while(strcmp(current -> key, k) != 0)
    {
        current = current -> next;
    }

    return &current -> value;
}
/*
 a simple yes/no if the key is in the hashtable.
 0 is no, all other values are yes.
 */
int containsKey (struct hashMap * ht, KeyType k)
{
    int index;
    index = stringHash2(k) % ht -> tableSize;

    if(index < 0)
    {
        index += ht -> tableSize;
    }

    struct hashLink *current = ht -> table[index];

    while(current)
    {
        if(strcmp(current -> key, k) == 0)
        {
            return 1;
        }

        current = current -> next;
    }

	return 0;
}

/*
 find the hashlink for the supplied key and remove it, also freeing the memory
 for that hashlink. it is not an error to be unable to find the hashlink, if it
 cannot be found do nothing (or print a message) but do not use an assert which
 will end your program.
 */
void removeKey (struct hashMap * ht, KeyType k)
{
	int index;
    index = stringHash2(k) % ht -> tableSize;

	if (index < 0)
	{
		index += ht -> tableSize;
	}

	struct hashLink *current = ht -> table[index];

	struct hashLink *previous = ht -> table[index];

	while (current != 0)
	{
		if (current -> key == k)
		{
			previous -> next = current -> next;

			free(current);

			return;
		}

		previous = current;
		current = current -> next;
	}
}

/*
 returns the number of hashLinks in the table
 */
int size (struct hashMap *ht)
{
	/*write this*/
	return ht -> count;

}

/*
 returns the number of buckets in the table
 */
int capacity(struct hashMap *ht)
{
	/*write this*/
	return ht -> tableSize;
}

/*
 returns the number of empty buckets in the table, these are buckets which have
 no hashlinks hanging off of them.
 */
int emptyBuckets(struct hashMap *ht)
{
    int empty;
    empty = 0;

    for (int i = 0; i < ht -> tableSize; i++)
    {
        if (ht -> table[i] == 0)
        {
            empty++;
        }
    }

    return empty;
}

/*
 returns the ratio of: (number of hashlinks) / (number of buckets)

 this value can range anywhere from zero (an empty table) to more then 1, which
 would mean that there are more hashlinks then buckets (but remember hashlinks
 are like linked list nodes so they can hang from each other)
 */
float tableLoad(struct hashMap *ht)
{
	float load;
    load = (float)size(ht) / capacity(ht);
	return load;
}
void printMap (struct hashMap * ht)
{
	int i;
	struct hashLink *temp;
	for(i = 0;i < capacity(ht); i++){
		temp = ht->table[i];
		if(temp != 0) {
			printf("\nBucket Index %d -> ", i);
		}
		while(temp != 0){
			printf("Key:%s|", temp->key);
			printValue(temp->value);
			printf(" -> ");
			temp=temp->next;
		}
	}
}
