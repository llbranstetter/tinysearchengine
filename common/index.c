/************* index module to support saving and loading index files ***
 * 
 * mapping from word to (docID, #occurrences) pairs. The index is a hashtable keyed by word and storing counters as items. 
 * The counters is keyed by docID and stores a count of the number of occurrences of that word in the document with that ID.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "hashtable.h" 
#include "set.h"
#include "pagedir.h"
#include "webpage.h"
#include "counters.h"
#include "file.h"
#include "word.h"

/***** local variables ***/
const int max_slots = 500;

/**************** global types ****************/
typedef struct index {
  struct hashtable *hashtable;       // hashtable that holds sets whos keys are words and items are counters
} index_t;

/*************** local functions *********/
static void key_print();
static void item_print();

/*********** global function **********/

/**** index_new function
 * creates a new index (an empty hashtable of max_slots number of slots)
 */
index_t*
index_new(void){
    index_t* index = mem_malloc(sizeof(index_t));

    if (index == NULL) {
    return NULL;              // error allocating bag
  } else {
    // initialize contents of bag structure
    index->hashtable = hashtable_new(max_slots);
    return index;
  }
}

/****** 
 * index_iterate function
 * 
 * this function iterates over every set in the hashtable and goes through every node in the set and every counter in the set
 * 
 * used for printing in index_save
 */
void
index_iterate(index_t* index, FILE* file){
   // Check for NULL pointers
    if (index == NULL || index->hashtable == NULL || file == NULL) {
        return;
    }

    // Iterate over the hashtable
    hashtable_iterate(index->hashtable, NULL, (void (*)(void*, const char*, void*))set_print);
}

/****** 
 * index_save function
 * 
 * opens a file for writing and prints the hashtable in index into that file (use fprintf)
 * saves index to a file that will be called in the calling of indexer.c
 * 
 * user provides: valid pointer to an index to print
 * valid filePath name
 * 
 * returns: NULL on error
 */
void
index_save(index_t* index, char* filePath){  

     // Open the file for writing
    FILE* file = fopen(filePath, "w");
    
    // Check if the file opened successfully
    if (file == NULL) {
        return false; // Return false on error
    }

    // print out the hashtable to the file
    index_iterate(index, file);

    // Close the file
    fclose(file);
    free(filePath);
    return true; // Return true if successful
}

void
index_addWord(index_t* index, char* word, int DocumentID){

    // normalize word
    word = normalizeWord(word);
    // initialize hashtable
    hashtable_t* hashtable = index->hashtable;

    // if no set exists:
    if (hashtable_find(hashtable, word) == NULL){
        // create a set at that index in the hashtable
        set_t* set = set_new();
        counters_t* counters = counters_new(); // the key, item pair in the set is a word, counters
        counters_add(counters, DocumentID); // add the documentID to the counters
        set_insert(set, word, counters);
        hashtable_insert(hashtable, word, set); // put the constructed set into the hashtable in the correct position
    }

    // if a set does exist in that position:
    else{
    // check if the key for that set has the same word
        set_t* priorset = hashtable_find(hashtable, word);
        if(setfind(priorset, word)){ // if the word is already in the set (check set_find):
            // increment the counters item with docID
            set_iterate(priorset, counters_t* counters, counters_add(counters, word)); // this feels wrong idk
        }
    // if the word is not in that set:
        else{
        // make a new set node and and set the item to a new counters
            counters_t* counters = counters_new();
            set_insert(priorset, word, counters);
        }
    }
    
}

void
index_delete(index_t* index, void (*itemdelete)(void* item) ){
    if (index == NULL){
        return; // bad index
    } 
    hashtable_delete(index->hashtable, (void (*)(void*))counters_delete()); // use a function casting (specifying )    
    mem_free(index);
}
