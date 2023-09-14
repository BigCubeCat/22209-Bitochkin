#include <gtest/gtest.h>

#include <BitArray.h>

TEST(BitArrayTests, SimpleSumTest
) {
auto ba = BitArray("1001");
EXPECT_EQ(1, ba.count());
}
