/****** implements normalizedWord */

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


/************** global functions ********/
char* normalizeWord(char* word){
    // Check if the input word is NULL
    if (word == NULL) {
        return NULL;
        printf(stderr, "invalid word");
    }
    
    // Get the length of the word
    int length = strlen(word);
    
    // Iterate through each character in the word
    for (int i = 0; i < length; i++) {
        // convert it to lowercase
        word[i] = tolower(word[i]);
    }
    
    // Return the normalized word
    return word;
}