#include <gtest/gtest.h>

#include "BitArray.h"

TEST(BitArrayTests, constructor) {
    auto first = BitArray("101");
    auto second = BitArray(3, 5);
    auto copy = BitArray(first);
    EXPECT_EQ(true, first == second && copy == first);
}

TEST(BitArrayTests, constructor_a) {
    auto first = BitArray(8, 0);
    EXPECT_EQ(8, first.size());
}
