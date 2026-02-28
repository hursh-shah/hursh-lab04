// heap.cpp
// Hursh Shah

#include "heap.h"
#include <iostream>
using std::cout;

// Builds a heap from the range [start, end) using the heapify algorithm
// Should run in O(n) time
Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end){
  for (std::vector<int>::iterator it = start; it != end; it++) {
    vdata.push_back(*it);
  }

  int n = vdata.size();
  for (int i = n / 2 - 1; i >= 0; i--) {
    int current = i;
    while (true) {
      int left = 2 * current + 1;
      int right = 2 * current + 2;
      int smallest = current;

      if (left < n && vdata[left] < vdata[smallest]) {
        smallest = left;
      }
      if (right < n && vdata[right] < vdata[smallest]) {
        smallest = right;
      }
      if (smallest == current) {
        break;
      }

      int temp = vdata[current];
      vdata[current] = vdata[smallest];
      vdata[smallest] = temp;
      current = smallest;
    }
  }
}

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  vdata.push_back(value);
  int current = vdata.size() - 1;

  while (current > 0) {
    int parent = (current - 1) / 2;
    if (vdata[current] < vdata[parent]) {
      int temp = vdata[current];
      vdata[current] = vdata[parent];
      vdata[parent] = temp;
      current = parent;
    } else {
      break;
    }
  }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  int n = vdata.size();
  if (n == 0) {
    return;
  }
  if (n == 1) {
    vdata.pop_back();
    return;
  }

  vdata[0] = vdata[n - 1];
  vdata.pop_back();
  n = vdata.size();

  int current = 0;
  while (true) {
    int left = 2 * current + 1;
    int right = 2 * current + 2;
    int smallest = current;

    if (left < n && vdata[left] < vdata[smallest]) {
      smallest = left;
    }
    if (right < n && vdata[right] < vdata[smallest]) {
      smallest = right;
    }
    if (smallest == current) {
      break;
    }

    int temp = vdata[current];
    vdata[current] = vdata[smallest];
    vdata[smallest] = temp;
    current = smallest;
  }
}

// Returns the minimum element in the heap
int Heap::top(){
  if (vdata.size() == 0) {
    return 0;
  }
  return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  return vdata.size() == 0;
}
    
