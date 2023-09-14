#include <gtest/gtest.h>

#include "BitArray.h"

TEST(BitArrayTests, resizeMinTest) {
    auto ba = BitArray("1001");
    ba.resize(2);
    EXPECT_EQ("10", ba.to_string());
}

TEST(BitArrayTests, resizeMaxTest) {
    auto ba = BitArray("1");
    ba.resize(4, true);
    EXPECT_EQ("1111", ba.to_string());
}

TEST(BitArrayTests, clearTest) {
    auto ba = BitArray("111");
    ba.clear();
    EXPECT_EQ(true, ba.empty());
}

TEST(BitArrayTests, push_backTest0) {
    auto ba = BitArray("0000000");
    ba.push_back(true);
    EXPECT_EQ("00000001", ba.to_string());
}

TEST(BitArrayTests, push_backTest1) {
    auto ba = BitArray("");
    ba.push_back(false);
    EXPECT_EQ("0", ba.to_string());
}

TEST(BitArrayTests, resetAllTest) {
    auto ba = BitArray("111");
    ba.reset();
    EXPECT_EQ("000", ba.to_string());
}

TEST(BitArrayTests, resetOneTest) {
    auto ba = BitArray("111");
    ba.reset(1);
    EXPECT_EQ("101", ba.to_string());
}

TEST(BitArrayTests, stringTest) {
    auto ba = BitArray(4, 8);
    EXPECT_EQ("0001", ba.to_string());
}

