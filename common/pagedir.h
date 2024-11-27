/*** pagedir.h file  ***
* defines the functions in pagedir.c
*
* used to parse a file
*
***/

#ifndef PAGEDIR_H
#define PAGEDIR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../libcs50/file.h"
#include "../libcs50/webpage.h"


/***********************************************************************
 * pagedir_init - creates a .crawler file to allow the tse to recognize that there is something to be crawled
 *
 * Caller provides:
 *    valid string that is the specific file that you are scraping
 *
 * Returns:
 *      true if file is sucessfully created
 *      false if file creation fails
 * 
 * Caller is responsible for:
 *      creating the .crawler file from the scraped file
 * 
 */

bool pagedir_init(const char* pageDirectory);

/***********************************************************************
 * pagedir_save - saves the page directory
 *
 * Caller provides:
 *    the webpage that has been crawled, the page directory, the documentID (this increments every time you read a webpage. It is just a helper to make sure you don't go past depth.)
 *
 * Returns:
 *      void (creates a file if successful)
 *
 * Caller is responsible for:
 *      
 */

void pagedir_save(webpage_t* webpage, const char* pageDirectory, int documentID);

/****
 * pagedir_validate function
 * 
 * validates whether or not a directory is produced by the crawler module and populated by .crawler files
 * 
 * takes a valid pageDirectory as a parameter
 * 
 * returns true if valid directory and false if invalid
 */
bool pagedir_validate(const char* pageDirectory);

/***** pagedir_load function
 * 
 * takes a crawler produced directory and loads a page from a file in that directory
 * 
 * takes a pageDirectory, a documentID from within that pageDirectory, and a webpage as parameters
 * 
 * returns error if it cannot load page
 */
void pagedir_load(const char* pageDirectory, int documentID, webpage_t* page);

#endif 