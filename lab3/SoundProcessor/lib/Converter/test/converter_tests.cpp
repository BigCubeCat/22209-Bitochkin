#include "gtest/gtest.h"
#include "converterFactory.h"

TEST(constructor_tests, converterFactory)
{
    std::vector<std::string> parameters = {"test"};
    try
    {
        converterFactory::ConverterFactory converterFactory;
        converterFactory::ConverterPointer pointer = converterFactory.createConverter(parameters);
    }

    catch(const converterFactory::NotFoundConverter& e)
    {
        EXPECT_STREQ(e.what(), "test not found");
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}