#include "gtest/gtest.h"
#include "converterFactory.h"

TEST(constructor_tests, mix) {
    std::vector<std::string> parameters = {"mix", "$2", "9000"};

    try {
        mix::Mix mix(parameters);
    }
    catch(const converter::WrongTime& e)
    {
        EXPECT_STREQ(e.what(), "9000 is wrong time format");
    }
}

TEST(constructor_tests, mute) {
    std::vector<std::string> parameters = {"mute", "40", "9000"};

    try {
        mix::Mix mix(parameters);
    }
    catch(const converter::WrongTime& e)
    {
        EXPECT_STREQ(e.what(), "9000 is wrong time format");
    }
}

TEST(constructor_tests, noise) {
    std::vector<std::string> parameters = {"noise", "40", "9000"};

    try {
        mix::Mix mix(parameters);
    }
    catch(const converter::WrongTime& e)
    {
        EXPECT_STREQ(e.what(), "9000 is wrong time format");
    }
}

TEST(constructor_tests, converterFactory)
{
    std::vector<std::string> parameters = {"pupok"};
    try
    {
        converterFactory::ConverterFactory converterFactory;
        converterFactory::ConverterPointer pointer = converterFactory.createConverter(parameters);
    }

    catch(const converterFactory::NotFoundConverter& e)
    {
        EXPECT_STREQ(e.what(), "pupok not found");
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}