#include <gtest/gtest.h>

#include <vector>

#include "heap.h"

using namespace std;

//! Tests Heap
class HeapTest : public ::testing::Test {
  public:
    //! Sets me up before each test
    void SetUp(Heap * heap) {
      myHeap = heap;
    }

    //! Tests insert and getMin methods
    void testInsertAndGetMin() {
      ASSERT_TRUE(myHeap);
      expectNewMin(3);
      expectNewMin(1);
      expectOldMin(5);
      expectOldMin(2);
    }

    //! Tests popMin method
    void testPopMin() {
      ASSERT_TRUE(myHeap);
      vector<int> in = { 2, 3, 4, 5};
      for (auto it = in.rbegin(); it != in.rend(); ++it) {
        myHeap->insert(*it);
      }
      for (auto & i : in) {
        EXPECT_EQ(i, myHeap->popMin());
      }
    }

    //! Tests hasMin method
    void testHasMin() {
      ASSERT_TRUE(myHeap);
      vector<int> in = { 2, 3 };
      EXPECT_FALSE(myHeap->hasMin());
      for (auto & i : in) {
        myHeap->insert(i);
        EXPECT_TRUE(myHeap->hasMin());
      }
      while (myHeap->hasMin()) {
        myHeap->popMin();
      }
      EXPECT_FALSE(myHeap->hasMin());
    }

    //! Tears me down after each test
    void TearDown() {
      delete myHeap;
      myHeap = NULL;
    }
  private:
    //! My heap to run tests on
    Heap * myHeap = NULL;

    //! Inserts new value in my heap and expects that min changed
    void expectNewMin(int value) {
      myHeap->insert(value);
      EXPECT_EQ(myHeap->getMin(), value);
    }

    //! Inserts new value in my heap and expects that min didn't change
    void expectOldMin(int value) {
      int oldMin = myHeap->getMin();
      myHeap->insert(value);
      EXPECT_EQ(myHeap->getMin(), oldMin);
    }
};

#include "binaryheapbuilder.h"

TEST_F(HeapTest, BinaryHeapInsertAndGetMin) {
  SetUp(BinaryHeapBuilder().build());
  testInsertAndGetMin();
}

TEST_F(HeapTest, BinaryHeapPopMin) {
  SetUp(BinaryHeapBuilder().build());
  testPopMin();
}

TEST_F(HeapTest, BinaryHeapHasMin) {
  SetUp(BinaryHeapBuilder().build());
  testHasMin();
}