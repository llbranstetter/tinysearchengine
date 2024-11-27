/*** pagedir.c file
 * opens a .crawler file for writing
 * allows crawler to write into that director
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../libcs50/file.h"
#include "../libcs50/webpage.h"

/*
* pagedir_init function
* see pagedir.h file for documentation on usage
*/
bool pagedir_init(const char* pageDirectory){
// construct the pathname for the .crawler file in that directory
    char* filePath = malloc(strlen(pageDirectory) + strlen("/.crawler") + 1); // +1 for null terminator
    sprintf(filePath, "%s/.crawler", pageDirectory);

    // Open the file for writing
    FILE* file = fopen(filePath, "w");
    
    // Check if the file opened successfully
    if (file == NULL) {
        return false; // Return false on error
    }

    // Close the file
    fclose(file);
    free(filePath);
    return true; // Return true if successful
}

/*
* pagedir_save function
* see pagedir.h file for documentation on usage
*/
void pagedir_save(webpage_t* webpage, const char* pageDirectory, int documentID){
    // construct the pathname for the page file
    
    char docIDstr[10];
    sprintf(docIDstr, "/%d", documentID);

    // creation of filename pageDirectory/docID
    // size of string is amount of digits + length of pagedir string + 1(for null)
    char filePath[strlen(docIDstr) + (strlen(pageDirectory)) + 1];

    strcpy(filePath, pageDirectory);
    strcat(filePath, docIDstr);

    printf(filePath, sizeof(filePath), "%s/%d.txt", pageDirectory, documentID);   
    // Open the file for writing
    FILE* file = fopen(filePath, "w");
    if (file == NULL) {
        return; // Handle error (could also print an error message)
    }
// print the URL
    fprintf(file, "URL: %s\n", webpage_getURL(webpage));
// print the depth
    fprintf(file, "depth: %d\n", webpage_getDepth(webpage));
// print the contents of the webpage
    
    fprintf(file, "HTML: %s\n", webpage_getHTML(webpage));
    
// close the file
    fclose(file);
    // free(filePath);
}

/****
 * pagedir_validate function
 * 
 * validates whether or not a directory is produced by the crawler module and populated by .crawler files
 * 
 * takes a valid pageDirectory as a parameter
 * 
 * returns true if valid directory and false if invalid
 */
bool pagedir_validate(const char* pageDirectory){

}

/***** pagedir_load function
 * 
 * takes a crawler produced directory and loads a page from a file in that directory
 * 
 * takes a pageDirectory, a documentID from within that pageDirectory, and a webpage as parameters
 * 
 * returns error if it cannot load page
 */
void pagedir_load(const char* pageDirectory, int documentID, webpage_t* page){
    // use pagedir_load to read data files. Use a loop to read files starting from 1 till n. Loop will end in n+1 because fopen for read will return null. 
}

