#
# Leah Branstetter
# indexer Makefile, fall 2024

OBJS = indextest.o index.o ../lib/file.o ../lib/mem.o 
LIBS =

# uncomment the following to turn on verbose memory logging
#TESTING=-DMEMTEST

CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) -I../lib -I../common
CC = gcc
MAKE = make
# for memory-leak tests
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all

indextest: $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

indextest.o: index.h ../lib/file.h ../common/pagedir.h ../libcs50/webpage.h ../libcs50/file.h ../libcs50/set.h ../libcs50/hashtable.h
index.o: index.h ../common/pagedir.h ../libcs50/webpage.h ../libcs50/file.h ../libcs50/set.h ../libcs50/hashtable.h


.PHONY: test valgrind clean


test: testing.sh index
	bash -v testing.sh 2&> testing.out


valgrind: testing 
	$(VALGRIND) ./testing.sh 

clean:
	rm -rf *.dSYM  # MacOS debugger info
	rm -f *~ *.o
	rm -f indextest
	rm -f core
