# Makefile for crawler
OBJS = crawler.o ../libcs50/libcs50.a ../common/common.a
LIB = ../libcs50/libcs50.a

CFLAGS = -Wall -pedantic -std=c11 -ggdb $(FLAGS)
CC = gcc
MAKE = make
# for memory-leak tests
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all

# Build $(LIB) by archiving object files
# (you will need to drop in copy of set.c, counters.c, hashtable.c)
crawler: $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@ 

# Dependencies: object files depend on header files
crawler.o: ../common/pagedir.h ../libcs50/webpage.h ../libcs50/file.h ../libcs50/bag.h ../libcs50/hashtable.h

# testing: new target to run testing.sh and output to testing.out
test: testing.sh crawler
	bash testing.sh 2&> testing.out

.PHONY: clean sourcelist test

# list all the sources and docs in this directory.
# (this rule is used only by the Professor in preparing the starter kit)
sourcelist: Makefile *.md *.c *.h *.sh
	@echo $^

# for valgrind testing:
valgrind: testing
	$(VALGRIND) ./testing.sh

# clean up after our compilation
clean:
	rm -f core
	rm -f $(LIB) *~ *.o testing.out