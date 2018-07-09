#include "pccb/chap2/minimum_spanning_tree/conscription.h"
#include <gtest/gtest.h>

TEST(conscription, simple)
{
    std::vector<ConscriptionRelation> relations;

    relations.emplace_back(4, 3, 6831);
    relations.emplace_back(1, 3, 4583);
    relations.emplace_back(0, 0, 6592);
    relations.emplace_back(0, 1, 3063);
    relations.emplace_back(3, 3, 4975);
    relations.emplace_back(1, 3, 2049);
    relations.emplace_back(4, 2, 2104);
    relations.emplace_back(2, 2, 781);

    const int cost = conscription(relations, 5, 5);
    EXPECT_EQ(71071, cost);
}
