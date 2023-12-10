#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "row.h"

class Counter {
   public:
    Counter(const std::string &inFile, const std::string &outFile);
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
};
