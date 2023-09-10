#include "./counter.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

Counter::Counter(std::string inFile, std::string outFile)
    : inputFile(inFile), outputFile(outFile) {
    parseFile();
    createTable();
}

/*
 * splitWords(words)
 * @param{words} words, joined by forbidden symbols
 * @returns vector of clean words
 */
std::vector<std::string> Counter::splitWords(std::string words) {
    std::vector<std::string> results;
    std::string currentWord = "";
    for (auto c : words) {
        if (SPLIT_CHARS.find(c) != std::string::npos) {
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

/*
 * parseFile()
 * reads input file word by word (separator is ' '),
 * splits words by non-alphabet symbols and add all symbols to statistic
 */
void Counter::parseFile() {
    std::string words;
    std::fstream file;
    file.open(inputFile, std::ios::in);

    while (std::getline(file, words, ' ')) {
        for (const auto& word : splitWords(words)) {
            const std::pair<std::string, int> pair{word, 1};
            if (auto [it, inserted] = statistic.insert(pair); !inserted) {
                it->second += 1;
            }
            countWords++;
        }
    }
}

/*
 * createTable()
 * reads statistic after "parseFile()" and generate table data
 */
void Counter::createTable() {
    table.reserve(statistic.size());
    for (const auto& it : statistic) {
        table.push_back(Row{it.first, it.second,
                            (float)it.second * 100 / (float)countWords});
    }
    std::sort(table.begin(), table.end());
}

/*
 * saveCSV()
 * Saves statistic to outputFile
 */
void Counter::saveCSV() {
    std::ofstream outFile;
    outFile.open(outputFile);
    outFile << "Word;count;frequency %\n";
    for (const auto& row : table) {
        outFile << row.word + ";" + std::to_string(row.count) + ";" +
                       std::to_string(row.frequency) + "\n";
    }
    outFile.close();
}
