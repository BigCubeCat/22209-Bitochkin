#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

const std::string SPLIT_CHARS = ",./:\\-+=()*&^%$#@!?<>\"\'";

class Counter {
public:
  std::string inputFile;
  std::string outputFile;
  std::map<std::string, int> statistic;
  int countWords = 0;

  Counter(std::string inFile, std::string outFile);
  void saveCSV();

private:
  std::map<std::string, bool> foundWords;
  void parseFile();
  std::vector<std::string> splitWords(std::string words);
};

bool isSplitChar(char c);
