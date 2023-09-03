#include "./counter.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
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
            countWords++;
            if (foundWords[word]) {
                statistic[word] += 1;
            } else {
                foundWords[word] = true;
                statistic[word] = 1;
            }
        }
    }
}

void Counter::createTable() {
    for (auto & it : statistic) {
        table.push_back(
            Row{it.first, it.second, it.second * 100 / countWords});
    }
    std::sort(table.begin(), table.end(), compareRows);
}

std::string Counter::generateFileContent() {
    std::string content = "Word;count;frequency\n";

    for (auto row : table) {
        content += row.word + ";" + std::to_string(row.count) + ";" +
                   std::to_string(row.frequency) + "\n";
    }
    return content;
}

void Counter::saveCSV() {
    std::ofstream outFile;
    outFile.open(outputFile);
    outFile << generateFileContent();
    outFile.close();
}
