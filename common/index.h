/******* 
 * index.h file for the tse indexer 
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../libcs50/hashtable.h" 
#include "../libcs50/set.h"
#include "../common/pagedir.h"
#include "../libcs50/webpage.h"
#include "../libcs50/counters.h"
#include "../libcs50/file.h"
#include "word.h"

/***** local variables ***/
const int max_slots = 500;

/**************** global types ****************/
typedef struct index {
  struct hashtable *table;       // hashtable that holds sets whos keys are words and items are counters
} index_t;


/*********** global function **********/

/**** index_new function
 * creates a new index (an empty hashtable of max_slots number of slots)
 * 
 * this function does not require arguments
 * it is called in indexBuild to initialize an index
 */
index_t*
index_new(void);

/****** 
 * index_iterate function
 * 
 * this function iterates over every set in the hashtable and goes through every node in the set and every counter in the set
 * do I even need an iterate function????
 */
void
index_iterate(index_t* index, void* arg, void (*itemfunc)(void* arg, void* item));
/****** 
 * index_save function
 * 
 * saves index to a file that will be called in the calling of indexer.c
 * 
 * This takes an index as parameter
 */
void
index_save(index_t* index);
/*****
 * 
 * 
 * assumes that if an item is already in the hashtable, it is a set
 */
void
index_addWord(index_t* index, word_t* word, int DocumentID);

void
index_delete(index_t* index, void (*itemdelete)(void* item) );
