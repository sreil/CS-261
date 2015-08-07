# ifndef HashMap
# define HashMap

# define KeyType char*
# define ValueType int

/*
 this is useful for you in answering the questions. if your write your code such
 that you call stringHash1 when HASHING_FUNCTION==1 and stringHash2 when
 HASHING_FUNCTION==2 then you only need to change this value in order to switch
 hashing functions that your code uses. you are not required to use this value
 though.
 */
# define HASHING_FUNCTION 2

# define LOAD_FACTOR_THRESHOLD 0.75

struct hashLink
{
   KeyType key; /*the key is what you use to look up a hashLink*/
   ValueType value; /*the value stored with the hashLink, an int in our case*/
   struct hashLink *next; /*notice how these are like linked list nodes*/
};

typedef struct hashLink hashLink;

struct hashMap
{
    hashLink ** table; /*array of pointers to hashLinks*/
    int tableSize; /*number of buckets in the table*/
    int count; /*number of hashLinks in the table*/
};

typedef struct hashMap hashMap;

/*the first hashing function you can use*/
int stringHash1(char * str);

/*the second hashing function you can use*/
int stringHash2(char * str);

/*initialize the supplied hashMap struct*/
void initMap (struct hashMap * ht, int tableSize);

struct hashMap *createMap(int tableSize);


void freeMap (struct hashMap * ht);
/*
 free all memory used for your hashMap, but do not free the pointer to ht. you
 can see why this would not work by examining main(). the hashMap passed into
 your functions was never malloc'ed, so it can't be free()'ed either.
 */
void deleteMap(struct hashMap *ht);

/*
 insert the following values into a hashLink, you must create this hashLink but
 only after you confirm that this key does not already exist in the table. you
 cannot have two hashLinks for the word "taco".

 if a hashLink already exists in the table for the key provided you should
 replace that hashLink (really this only requires replacing the value v).
 */
void insertMap (struct hashMap * ht, KeyType k, ValueType v);

/*
 this returns a POINTER to the value stored in a hashLink specified by the key k.

 if the user supplies the key "taco" you should find taco in the hashTable, then
 return a pointer to the value member of the hashLink that represents taco. keep
 in mind we are storing an int for value, so you don't use malloc or anything.

 if the supplied key is not in the hashtable return NULL.
 */
ValueType* atMap (struct hashMap * ht, KeyType k);

/*
 a simple yes/no if the key is in the hashtable. 0 is no, all other values are
 yes.
 */
int containsKey (struct hashMap * ht, KeyType k);

/*
 find the hashlink for the supplied key and remove it, also freeing the memory
 for that hashlink. it is not an error to be unable to find the hashlink, if it
 cannot be found do nothing (or print a message) but do not use an assert which
 will end your program.
 */
void removeKey (struct hashMap * ht, KeyType k);

/*
 returns the number of hashLinks in the table
 */
int size (struct hashMap *ht);

/*
 returns the number of buckets in the table
 */
int capacity(struct hashMap *ht);

/*
 returns the number of empty buckets in the table, these are buckets which have
 no hashlinks hanging off of them.
 */
int emptyBuckets(struct hashMap *ht);

/*
 returns the ratio of: (number of hashlinks) / (number of buckets)

 this value can range anywhere from zero (an empty table) to more then 1, which
 would mean that there are more hashlinks then buckets (but remember hashlinks
 are like linked list nodes so they can hang from each other)
 */
float tableLoad(struct hashMap *ht);

void printMap (struct hashMap * ht);

void printValue(ValueType v);


# endif
