#include "algorithm/bucket_method/range_minimum_query.h"
#include <vector>
#include <gtest/gtest.h>

namespace pccb {
namespace bucket_method {
TEST(bucket_method, RangeMinimumQuerySimple)
{
  int data[] = {
    1,
    3,
    4,
    5,
    7,
    7,
    7,
    7,
  };
  const int size = 8;
  const int size_bucket = RangeMinimumQueryGetSize(size);
  int bucket[size_bucket];
  RangeMinimumQueryInit(data, size, bucket);

  const int actual = RangeMinimumQueryQuery(data, bucket, size, 0, size - 1);
  EXPECT_EQ(1, actual);
}
} // namespace bucket_method
} // namespace pccb
