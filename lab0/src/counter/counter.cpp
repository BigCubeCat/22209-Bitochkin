#include "./counter.h"
#include "./row.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

bool isSplitChar(char c) {
  for (auto splitChar : SPLIT_CHARS) {
    if (c == splitChar) {
      return true;
    }
  }
  return false;
}

Counter::Counter(std::string inFile, std::string outFile) {
  inputFile = inFile;
  outputFile = outFile;
  parseFile();
  createTable();
}

std::vector<std::string> Counter::splitWords(std::string words) {
  std::vector<std::string> results;
  std::string currentWord = "";
  for (auto c : words) {
    if (isSplitChar(c)) {
      if (currentWord.length() > 0) {
        results.push_back(currentWord);
        currentWord = "";
      }
    } else {
      currentWord += c;
    }
  }
  if (currentWord.length() > 0) {
    results.push_back(currentWord);
    currentWord = "";
  }
  return results;
}

void Counter::parseFile() {
  std::string words;
  std::fstream file;
  file.open(inputFile, std::ios::in);

  while (file.peek() != EOF) {
    getline(file, words, ' ');
    for (auto word : splitWords(words)) {
      std::cout << word << std::endl;
      countWords++;
      if (foundWords[word]) {
        statistic[word]++;
      } else {
        foundWords[word] = true;
        statistic[word] = 0;
      }
    }
  }
}

void Counter::createTable() {
  std::cout << "here\n";
  for (std::map<std::string, int>::iterator it = statistic.begin();
       it != statistic.end(); ++it) {
    table.push_back(Row{it->first, it->second, it->second * 100 / countWords});
  }
  std::sort(table.begin(), table.end(), compareRows);
}

void Counter::saveCSV() {}
