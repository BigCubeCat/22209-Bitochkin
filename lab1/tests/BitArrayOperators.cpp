#include <gtest/gtest.h>

#include "BitArray.h"

TEST(BitArrayTests, swapTest) {
    auto first = BitArray("101");
    auto second = BitArray("1000");
    first.swap(second);
    EXPECT_EQ("1000", first.to_string());
}

TEST(BitArrayTests, eqTest) {
    BitArray first;
    first = BitArray("0");
    EXPECT_EQ("0", first.to_string());
}

TEST(BitArrayTests, binAndEqOperatorTest) {
    BitArray ba = BitArray("10010");
    ba &= BitArray("11");
    EXPECT_EQ("10", ba.to_string());
}

TEST(BitArrayTests, binOrEqOperatorTest) {
    BitArray ba = BitArray("100");
    ba |= BitArray("010");
    EXPECT_EQ("110", ba.to_string());
}

TEST(BitArrayTests, binXOrEqOperatorTest) {
    BitArray ba = BitArray("000");
    ba ^= BitArray("010");
    EXPECT_EQ("010", ba.to_string());
}

TEST(BitArrayTests, leftShiftTest) {
    BitArray ba = BitArray("111");
    ba <<= 2;
    EXPECT_EQ("11100", ba.to_string());
}

TEST(BitArrayTests, rightShiftTest) {
    BitArray ba = BitArray("1000");
    ba >>= 1;
    EXPECT_EQ("100", ba.to_string());
}

TEST(BitArrayTests, notTest) {
    EXPECT_EQ("0111", (~BitArray("1000")).to_string());
}

TEST(BitArrayTests, indexTest) {
    auto ba = BitArray("010");
    EXPECT_EQ(true, ba[1]);
}

TEST(BitArrayTests, eq_Test) {
    auto a = BitArray("010");
    auto b = BitArray("010");
    EXPECT_EQ(true, a == b);
}

TEST(BitArrayTests, neqTest) {
    auto a = BitArray("010");
    auto b = BitArray("010");
    EXPECT_EQ(false, a != b);
}

TEST(BitArrayTests, andOperTest) {
    auto a = BitArray("110");
    auto b = BitArray("010");
    EXPECT_EQ("010", (a & b).to_string());
}

TEST(BitArrayTests, orOperTest) {
    auto a = BitArray("110");
    auto b = BitArray("010");
    EXPECT_EQ("110", (a | b).to_string());
}

TEST(BitArrayTests, xorOperTest) {
    auto a = BitArray("110");
    auto b = BitArray("010");
    EXPECT_EQ("100", (a ^ b).to_string());
}
