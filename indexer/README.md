# README file for indexer module
## cs50 Fall2024 tse

### indexer

A crawler takes in a website url and searches through the website for any other urls within it. It then put all of those urls into a bag and goes through them one by one to find all of the urls in each of those websites. It will do this until it hits the maximum depth of website crawl or until it has crawled every website in the bag. It prints out the urls of all of these websites along with a webpage ID and the pagedirectory in which it's found.

### Usage

The crawler module implements crawler.c using testing.sh and prints the output to testing.out.

```c
int main(const int argc, char* argv[]);
static void parseArgs(const int argc, char* argv[],
                      char** seedURL, char** pageDirectory, int* maxDepth);
static void crawl(char* seedURL, char* pageDirectory, const int maxDepth);
static void pageScan(webpage_t* page, bag_t* pagesToCrawl, hashtable_t* pagesSeen);
```

### Implementation

Crawler is implemented using the bag, hashtable, and website structures provided in the lab starter kit. 

Each node in the bag is a char* url for a website. Similarly each key in the hashtable is a char* url for a website with a blank string as its item. The hashtable checks that the same url is not being printed multiple times, while the bag keeps track of the items.

The main function calls parseArgs and crawl to parse the arguments and check that they are all valid (check that a valid website url, pageDirectory, and maxDepth are given). Then it calls crawl with the arguments from parseArgs. pageScan is a helper function for crawl to go through a webpage and extract any links.

### Assumptions

No assumptions beyond those that are clear from the spec.

the program will print an error message if the user enters invalid arguments. 

### Files

* `Makefile` - compilation procedure
* `crawler.c` - the implementation
* `testing.sh` - unit test driver
* `testing.out` - result of `make test &> testing.out`

### Compilation

To compile, simply `make`.

### Testing

The `testing.sh` program calls the crawler file with both valid and invalid inputs and prints the output to testing.out.
It tests a few error and edge cases including invalid url, invlaid directory, and two types of invalid maxDepth values.

To test, simply `make test`.
See `testing.out` for details of testing and an example test run.

To test with valgrind, `make valgrind`.