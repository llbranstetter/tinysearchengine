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
#include "../common/index.h"
#include "../common/word.h"


/***** parseArgs
 * takes in a pagedirectory and filename as aruguments
 * 
 * parse the arguments given
 * checks that the arguments given are valid
 * 
 * returns error if arguments are invalid or cannot be parsed 
 * 
 * make sure it takes blank files
 */
static void
parseArgs(const int argc, char* argv[], char** pageDirectory, char** filename){

}
/****** indexBuild
 * 
 *  builds an in-memory index from webpage files it finds in the pageDirectory
 * 
 * takes in a pageDirectory as parameters and goes through each webpage in that directory 
 * checks validity of each website and passes valid webpages to indexPage
 * 
 * returns an error if unable to parse webpages and 
 */


static void
indexBuild(pagedir_t* pagedir){
    //  creates a new 'index' object
    index_t* index = index_new();
    //   loops over document ID numbers, counting from 1
    //     loads a webpage from the document file 'pageDirectory/id'
    //     if successful, 
    //       passes the webpage and docID to indexPage
}

/*******
 * indexPage
 * 
 * scans a webpage document to add its words to the index
 * 
 * takes in a valid webpage pointer as parameters
 * 
 * returns error message if unable to add words to index
 */
static void
indexPage(webpage_t* webpage){
    
    char* word = NULL;
    int pos = 0;
//    steps through each word of the webpage,
    While(word = webpage_getNextWord(webpage, pos)){
        //    skips trivial words (less than length 3),
        //    normalizes the word (converts to lower case),
        //    looks up the word in the index,
        //      adding the word to the index if needed
                // (words –> documents)
        //    increments the count of occurrences of this word in this docID
    }

}

/*****
 * main function
 * 
 * takes in arguments and builds program
 * passes arguments to indexBuild with pageDirectory
 */
int main(const int argc, char* argv[]){

    char* pageDirectory = NULL;
    char* filename = NULL;

    parseArgs(argc, argv, &pageDirectory, &filename);
    indexBuild(pageDirectory); 
}