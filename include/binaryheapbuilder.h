#ifndef BINARY_HEAP_BUILDER_H
#define BINARY_HEAP_BUILDER_H

#include "heapbuilder.h"
#include "binaryheap.h"

//! I am a BinaryHeap HeapBuilder.
class BinaryHeapBuilder : public HeapBuilder {
public:
  BinaryHeap * build() const override;
};

#endif // BINARY_HEAP_BUILDER_H