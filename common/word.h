/****** word.h file for the word module */

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
char* normalizeWord(char* word);