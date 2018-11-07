#pragma once
#include <gtest/gtest.h>

#define EXPECT_EQ_WITH_INDEX(expect,actual,index) EXPECT_EQ((expect), (actual)) << "Failed at index " << (index);

