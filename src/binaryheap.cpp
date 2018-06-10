#include "binaryheap.h"  

void BinaryHeap::insert(const int & elem) {
  myElems.push_back(elem);
  bubbleUp(myElems.size() - 1);
}

const int & BinaryHeap::getMin() const {
  return myElems.at(0);
}

int BinaryHeap::popMin() {
  int oldMin = myElems.at(0);
  if (myElems.size() > 1) {
    swapElems(0, myElems.size() - 1);
    myElems.pop_back();
    bubbleDown(0);
  }
  else {
    myElems.pop_back();
  }
  return oldMin;
}

bool BinaryHeap::hasMin() const {
  return !myElems.empty();
}

void BinaryHeap::bubbleUp(size_t pos) {
  if (pos == 0) {
    return;
  }
  const int parentId = (pos + 1) / 2 - 1;
  if (myElems[parentId] < myElems[pos]) {
    return;
  }
  swapElems(parentId, pos);
  bubbleUp(parentId);
}

void BinaryHeap::bubbleDown(size_t pos) {
  if (pos >= (myElems.size() - 1)) {
    return;
  }
  const size_t childOne = (pos + 1) * 2 - 1;
  const size_t childTwo = (pos + 1) * 2;
  size_t minChild = pos;
  if (childOne < myElems.size()
      && myElems[childOne] < myElems[minChild]) {
    minChild = childOne;
  }
  if (childTwo < myElems.size()
      && myElems[childTwo] < myElems[minChild]) {
    minChild = childTwo;
  }
  if (minChild == pos) {
    return;
  }
  swapElems(minChild, pos);
  bubbleDown(minChild);
}

void BinaryHeap::swapElems(size_t onePos, size_t twoPos) {
  size_t elem = myElems[onePos];
  myElems[onePos] = myElems[twoPos];
  myElems[twoPos] = elem;
}
