all: examheap

examheap: examheap.cpp heap.cpp heap.h
	g++ -std=c++17 examheap.cpp heap.cpp -o examheap

clean:
	rm -f examheap *.o
