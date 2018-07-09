#pragma once

#define GTEST_EXPECT_EQ_ELEMENT(expect, actual)  \
    do {                                         \
        auto e = expect.begin();                 \
        auto a = actual.begin();                 \
        while (e != expect.begin()) {            \
            EXPECT_EQ(*e, *a);                   \
            ++e;                                 \
            ++a;                                 \
        }                                        \
    } while (false)
