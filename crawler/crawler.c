/******* CS50 crawler.c file  
 *starts at a webpage and scans the webpage for  *******/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include "../libcs50/hashtable.h" 
#include "../libcs50/bag.h"
#include "../common/pagedir.h"
#include "../libcs50/webpage.h"
#include "../libcs50/file.h"

/******* functions for crawler *******/
int main(const int argc, char* argv[]);
static void parseArgs(const int argc, char* argv[],
                      char** seedURL, char** pageDirectory, int* maxDepth);
static void crawl(char* seedURL, char* pageDirectory, const int maxDepth);
static void pageScan(webpage_t* page, bag_t* pagesToCrawl, hashtable_t* pagesSeen);

/*******  parseArgs function checks that arguments are valid and parses them for use in the crawler funciton */
static void parseArgs(const int argc, char* argv[], char** seedURL, char** pageDirectory, int* maxDepth){
    
    // check if you got 3 arguments
    if(argc != 4){
        fprintf(stderr, "Incorrect number of arguments\n");
        exit(1); // different exit codes for faliure
    }

    // check that the first arg is a URL and that it's a url from the class website
    *seedURL = normalizeURL(argv[1]);
    if(*seedURL == NULL || isInternalURL(*seedURL) == false){
        fprintf(stderr, "Invalid URL\n");
        exit(2); 
    }
    *pageDirectory = argv[2];

    // check that the second parameter is a directory (it has to already exist)
    if(pagedir_init(*pageDirectory) == false){
        fprintf(stderr, "Invalid pageDirectory\n");
        exit(3);
    }
    // check that depth is an int
    errno = 0;
    char* endptr;
    *maxDepth = (int) strtol(argv[3], &endptr, errno);
    if (argv[1] == endptr || errno || *endptr != '\0'){
        fprintf(stderr, "maxDepth is not an integer.\n");
        exit(4);
    } 
    // check that depth is >= 0
    if(*maxDepth < 0){
        fprintf(stderr, "Invalid maxDepth value\n");
        exit(5);
    }
}

 

static void crawl(char* seedURL, char* pageDirectory, const int maxDepth){
//     initialize the hashtable and add the seedURL
    hashtable_t* hashtable = hashtable_new(maxDepth);
    hashtable_insert(hashtable, seedURL, "");
// initialize the bag and add a webpage representing the seedURL at depth 0
    bag_t* pagebag = bag_new();
    bag_insert(pagebag, webpage_new(seedURL, 0, NULL));

    // initialize documentID
    int documentID = 0;

// while bag is not empty
    webpage_t* page;
    while((page = bag_extract(pagebag)) != NULL){
//      pull a webpage from the bag
         
        //      fetch the HTML for that webpage
        
    //  if fetch was successful,
        if (webpage_fetch(page)){
            //save the webpage to pageDirectory   
            
            fprintf(stdout, "\nfetched: %s\n", webpage_getURL(page));
 
            pagedir_save(page, pageDirectory, documentID);
            documentID++;

            // if the webpage is not at maxDepth,
            if (documentID <= maxDepth + 1){
                // pagescan that html
                fprintf(stdout, "scanning: %s\n", webpage_getURL(page));
                pageScan(page, pagebag, hashtable);
                // you don't actually need to print the pageDirectory and docID
                // fprintf(stderr, "%s %d\n", pageDirectory, documentID);
            }
        }
//      delete that webpage
       webpage_delete(page);
    }
// delete the hashtable
    hashtable_delete(hashtable, NULL); // I feel like this is the wrong call here 
// delete the bag
    bag_delete(pagebag, webpage_delete);  
}

/*****
 * function pageScan takes a webpage and scans that page to extract any links (ignoring links outside the cs50lib or links it has already seen)
 */
static void pageScan(webpage_t* page, bag_t* pagesToCrawl, hashtable_t* pagesSeen){
// while there is another URL in the page
    char* url;
    int pos = 0;
    while((url = webpage_getNextURL(page, &pos)) != NULL){
        
        // all of the pages from this page are going to be at a depth that is one lower than the page they are on
        int depth = webpage_getDepth(page) + 1;

        // Normalize the URL before processing
        char* normalizedURL = normalizeURL(url);

        // if that URL is Internal
        if(isInternalURL(normalizedURL) == true){   
        // 	insert the webpage into the hashtable
        // 	if that succeeded,
            if(hashtable_insert(pagesSeen, normalizedURL, "") == true){
                
                webpage_t* webpage = webpage_new(normalizedURL, depth, NULL); //        create a webpage_t for it
                bag_insert(pagesToCrawl, webpage); //   insert the webpage into the bag
                fprintf(stdout, "added: %s\n", normalizedURL);
            }
        // free the URL
            else{
                fprintf(stdout, "IgnDupl: %s\n", normalizedURL);
                free(normalizedURL);
            }
        }
        else{
            fprintf(stdout, "IgnExtrn: %s\n", normalizedURL);
            free(normalizedURL);
        }
        
    free(url);  
    }
}

/*****
 * main function initializes arguments and runs parseArgs and crawl
 */

int main(const int argc, char* argv[]){ // takes in input of the seedURL, pageDirectory and maxDepth (in that order)

    char* seedURL = NULL;
    char* pageDirectory = NULL;
    int maxDepth;

    parseArgs(argc, argv, &seedURL, &pageDirectory, &maxDepth);
    crawl(seedURL, pageDirectory, maxDepth); 

}
