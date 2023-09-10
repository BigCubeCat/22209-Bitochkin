#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "row.h"

namespace {
const std::string SPLIT_CHARS = ",./:\\-+=()*&^%$#@!?<>\"\'\n\t[];<>_~`";
}

class Counter {
   public:
    Counter(std::string inFile, std::string outFile);
    void saveCSV();

   private:
    std::string inputFile;
    std::string outputFile;
    std::map<std::string, int> statistic;
    std::vector<Row> table;
    int countWords = 0;

    std::map<std::string, bool> foundWords;
    void parseFile();
    void createTable();
    static std::vector<std::string> splitWords(std::string words);
};
