# README file for common module
## cs50 Fall2024 tse

### common

The common directory holds various helper files for the tse. Currently, it includes only the pagedir.c and pagedir.h files, but it will be updated to include index.c and index.h files in the next portion of this lab. The pagedir files help to create and save a page directory that stores visited webpages.

### Usage

The common module creates pagedir.c which is used in crawler.c in the crawler module.

```c
bool pagedir_init(const char* pageDirectory);
void pagedir_save(webpage_t* webpage, const char* pageDirectory, int documentID);
```

### Implementation

pagedir.h is implemented in crawler.c in the parseArgs and crawl functions. 

The pagedir_init function takes a pageDirectory as input and creates a .crawler file to allow the tse to recognize that there is something to crawl. It returns true if the file is successfully created and false if it is not. It is used in paseArgs to check that the passed parameter is a valid directory.

the pagedir_save fucntion takes a webpage, pageDirectory, and documentID as input and saves the directory. It is called in the crawl function of crawler.c to save each webpage to a pageDirectory.

### Assumptions

No assumptions beyond those that are clear from the spec.


### Files

* `Makefile` - compilation procedure
* `pagedir.h` - the interface
* `pagedir.c` - the implementation

### Compilation

To compile, simply `make`.

### Testing

The testing for this file is done through the crawler testing as it is implemented in crawler. To check testing, run `make test` in the crawler module.