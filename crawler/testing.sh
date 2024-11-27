# $ crawler seedURL pageDirectory maxDepth
# create directory for crawled websites in the lettes playground:
mkdir ../data/letters # (this only needs to be done once)
# crawl websites and store them in above directory
# check with valgrind:
valgrind --leak-check=full ./crawler http://cs50tse.cs.dartmouth.edu/tse/letters/index.html ../data/letters 2

echo "check with too few arguments:";
./crawler http://cs50tse.cs.dartmouth.edu/tse/letters/index.html ../data/letters
echo "check with invalid webpage: ";
./crawler http://www.invalid.edu/.html ../data/letters 2
echo "check with invalid pageDirectory:";
./crawler http://cs50tse.cs.dartmouth.edu/tse/letters/index.html ../invalid/data 2
echo "check with negative maxDepth: ";
./crawler http://cs50tse.cs.dartmouth.edu/tse/letters/index.html ../data/letters -2
echo "check with non int maxDepth: ";
./crawler http://cs50tse.cs.dartmouth.edu/tse/letters/index.html ../data/letters hello
./crawler http://cs50tse.cs.dartmouth.edu/tse/letters/index.html ../data/letters 1.231

# testing with different websites: letters at depths 0,1,2,10, toscrape at depths 0,1,2,3, wikipedia at depths 0,1,2)
./crawler http://cs50tse.cs.dartmouth.edu/tse/letters/index.html ../data/letters 0
./crawler http://cs50tse.cs.dartmouth.edu/tse/letters/index.html ../data/letters 1
./crawler http://cs50tse.cs.dartmouth.edu/tse/letters/index.html ../data/letters 10
 
# testing with different seedURL:
./crawler http://cs50tse.cs.dartmouth.edu/tse/letters/A.html ../data/letters 3
 
# testing with larger playground:
mkdir ../data/toscrape
./crawler http://cs50tse.cs.dartmouth.edu/tse/toscrape/index.html ../data/toscrape 0
./crawler http://cs50tse.cs.dartmouth.edu/tse/toscrape/index.html ../data/toscrape 1
./crawler http://cs50tse.cs.dartmouth.edu/tse/toscrape/index.html ../data/toscrape 2
 
# trying out with wikipedia
mkdir ../data/wikipedia
./crawler http://cs50tse.cs.dartmouth.edu/tse/wikipedia/index.html ../data/wikipedia 0
#./crawler http://cs50tse.cs.dartmouth.edu/tse/wikipedia/index.html ../data/wikipedia 1
#./crawler http://cs50tse.cs.dartmouth.edu/tse/wikipedia/index.html ../data/wikipedia 2