#ifndef HEAP_H
#define HEAP_H

//! I am a minimal heap. I store my elements and I know the minimum one.
class Heap {
public:
  virtual ~Heap() {}
  //! Inserts new element in my elements
  virtual void insert(const int & elem) = 0;
  //! Gets my minimum
  virtual const int & getMin() const = 0;
  //! Pops out my minimum
  virtual int popMin() = 0;
  //! Returns true if I has some minimum
  virtual bool hasMin() const = 0;
};

#endif // HEAP_H