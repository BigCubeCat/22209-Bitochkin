#include "gtest/gtest.h"
#include "reader.h"
#include "writer.h"
#include <filesystem>

TEST(constructor_tests, copy_file) {

    std::filesystem::path cwd = std::filesystem::current_path();
    std::string pathFolder = cwd.string() + "/../" + "examples\\";
    const std::string path = pathFolder + "district_four.wav";

    {
        reader::Reader reader;
        reader.load(path);

        const std::string path1 = pathFolder + "a.wav";
        writer::Writer writer(path1);

        while (true) {
            wav::SampleBuffer buffer;
            if (!reader.readSample(&buffer)) break;
            writer.writeSample(&buffer);
        }

        writer.writeHeader();
    }

    reader::Reader reader1;
    reader::Reader reader2;
    reader1.load(pathFolder + "district_four.wav");
    reader2.load(pathFolder + "a.wav");

    while (true)
    {
        wav::SampleBuffer buffer1;
        wav::SampleBuffer buffer2;
        if (!reader1.readSample(&buffer1) || !reader2.readSample(&buffer2)) break;
        EXPECT_EQ(buffer1, buffer2);
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}