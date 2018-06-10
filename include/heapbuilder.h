#ifndef HEAP_BUILDER_H
#define HEAP_BUILDER_H

#include "heap.h"

//! I am a heap builder.
class HeapBuilder {
public:
  virtual ~HeapBuilder() {}
  //! Builds new heap
  virtual Heap * build() const = 0;
};

#endif // HEAP_BUILDER_H