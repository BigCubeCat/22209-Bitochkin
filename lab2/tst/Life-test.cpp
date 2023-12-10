#include "../App/Kernel/Life/Life.h"
#include "../App/Kernel/types/TRules.h"

#include "gtest/gtest.h"

TEST(LifeTest, InitTest) {
    Life life = Life(16, 32);
    EXPECT_EQ(life.getHeight(), 32);
    EXPECT_EQ(life.getWidth(), 16);
}

TEST(LifeTest, RunTest) {
    Life life = Life(3, 3);
    life.toggleCell(1, 1);
    life.toggleCell(0, 1);
    life.toggleCell(2, 1);
    life.nextGen();

    EXPECT_EQ(1, life[4]);
    EXPECT_EQ(1, life[3]);
    EXPECT_EQ(1, life[5]);
}

TEST(LifeTest, GetArenaTest) {
    Life life = Life(3, 3);
    auto res = life.getArena();

    EXPECT_FALSE(res == nullptr);
}

TEST(LifeTest, NeighborhoodTest) {
    Life life = Life(3, 3);
    life.setNeighborhood(TNeighborhood(VON, 2));
    EXPECT_EQ("V 2", life.getNeighborhood());
}

TEST(LifeTest, RulesTest) {
    Life life = Life(3, 3);
    EXPECT_EQ("B3/S2,3", life.getRules());
}