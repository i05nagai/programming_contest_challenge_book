#include "pccb/chap2/heap/heap.h"
#include <gtest/gtest.h>

TEST(heap, simple1)
{
  constexpr int length = 5;
  int heap[length];
  std::vector<int> inserter = {
    4, 2, 3, 1, 5,
  };
  // push
  for (int i = 0; i < inserter.size(); ++i) {
    heap_push(heap, inserter[i]);
  }
  std::vector<int> expects = {
    1, 2, 3, 4, 5,
  };
  // pop
  for (int i = 0; i < expects.size(); ++i)
    const int actual = heap_pop(heap);
    EXPECT_EQ(expects[i], actual);
  }
}
