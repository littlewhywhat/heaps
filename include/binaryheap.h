#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <heap.h>

#include <vector>

using namespace std;

//! I am a binary Heap.
class BinaryHeap : public Heap {
public:
  void insert(const int & elem) override;
  const int & getMin() const override;
  int popMin() override;
  bool hasMin() const override;
private:
  //! My elements
  vector<int> myElems;
  //! Bubbles up element in myElems at position pos
  void bubbleUp(size_t pos);
  //! Bubbles down element in myElems at position pos
  void bubbleDown(size_t pos);
  //! Swaps elems in myElems at positions onePos and twoPos
  void swapElems(size_t onePos, size_t twoPos);
};

#endif // BINARY_HEAP_H