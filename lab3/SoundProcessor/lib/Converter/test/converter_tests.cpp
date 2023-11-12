#include "converterFactory.h"
#include "gtest/gtest.h"


TEST(constructor_tests, mix) {
    std::vector<std::string> parameters = {"mix", "$2", "9000"};
    auto c = mix::Mix(parameters);
    c.eh->hasErrors();
    EXPECT_TRUE(c.eh->hasErrors());
}

TEST(constructor_tests, mute) {
    std::vector<std::string> parameters = {"mute", "40", "9000"};
    auto c = mute::Mute(parameters);
    EXPECT_TRUE(c.eh->hasErrors());
}

TEST(constructor_tests, noise) {
    std::vector<std::string> parameters = {"noise", "40", "9000"};
    auto c = noise::Noise(parameters);
    EXPECT_TRUE(c.eh->hasErrors());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
