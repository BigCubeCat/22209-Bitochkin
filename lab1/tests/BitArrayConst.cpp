#include <gtest/gtest.h>

#include "BitArray.h"

TEST(BitArrayTests, countTest) {
    auto ba = BitArray("1001");
    EXPECT_EQ(2, ba.count());
}

TEST(BitArrayTests, sizeTest) {
    auto ba = BitArray("000000");
    EXPECT_EQ(6, ba.size());
}

TEST(BitArrayTests, noneTest) {
    auto ba = BitArray("00000");
    EXPECT_EQ(true, ba.none());
}

TEST(BitArrayTests, anyTestTrue) {
    auto ba = BitArray("000010000");
    EXPECT_EQ(true, ba.any());
}

TEST(BitArrayTests, anyTestFalse) {
    auto ba = BitArray("0");
    EXPECT_EQ(false, ba.any());
}

TEST(BitArrayTests, emptyTrueTest) {
    auto ba = BitArray("");
    EXPECT_EQ(true, ba.empty());
}

TEST(BitArrayTests, emptyFalseTest) {
    auto ba = BitArray("00010");
    EXPECT_EQ(false, ba.empty());
}

TEST(BitArrayTests, n0neTest) {
    auto ba = BitArray("000");
    EXPECT_EQ(true, ba.none());
}
