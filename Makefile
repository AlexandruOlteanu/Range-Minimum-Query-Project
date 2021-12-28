CC = g++
CFLAGS = -Wall -Wextra -O2
LDLIBS = -lm

build: SparseTable_test.o SegmentTree_test.o SquareRootDecomposition_test.o

run-best:
	./test1

run-p1:
	./test1

run-p2:
	./test2

run-p3:
	./test3

SparseTable.o: SparseTable.cpp
	g++ SparseTable.cpp -c $(CFLAGS)

SparseTable_test.o: algo_test.cpp SparseTable.o
	g++ SparseTable.o algo_test.cpp -o test1 $(CFLAGS)

SegmentTree.o: SegmentTree.cpp
	g++ SegmentTree.cpp -c $(CFLAGS)

SegmentTree_test.o: algo_test.cpp SegmentTree.o
	g++ SegmentTree.o algo_test.cpp -o test2 $(CFLAGS)

SquareRootDecomposition.o: SquareRootDecomposition.cpp
	g++ SquareRootDecomposition.cpp -c $(CFLAGS)

SquareRootDecomposition_test.o: algo_test.cpp SquareRootDecomposition.o
	g++ SquareRootDecomposition.o algo_test.cpp -o test3 $(CFLAGS)

.PHONY: clean

clean:
	rm -rf *.o test1 test2 test3 test.in test.out