#include "./counter.h"
#include <fstream>
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
