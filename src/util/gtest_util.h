#pragma once
#include <gtest/gtest.h>
#include <limits>

#define EXPECT_EQ_WITH_INDEX(expect,actual,index) EXPECT_EQ((expect), (actual)) << "Failed at index " << (index);
#define EXPECT_EQ_DOUBLE(expect,actual) EXPECT_NEAR((expect), (actual), std::numeric_limits<double>::epsilon());

