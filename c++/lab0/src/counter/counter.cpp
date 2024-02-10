#include "./counter.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace {
const std::string SPLIT_CHARS = ",./:\\-+=()*&^%$#@!?<>\"\'\n\t[];<>_~`";
/*
 * splitWords(words)
 * @param{words} words, joined by forbidden symbols
 * @returns vector of clean words
 */
std::vector<std::string> splitWords(const std::string& words) {
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
}  // namespace

Counter::Counter(const std::string& inFile, const std::string& outFile)
    : inputFile(inFile), outputFile(outFile) {
    parseFile();
    createTable();
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
            if (auto [it, inserted] = statistic.insert({word, 1}); !inserted) {
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
    for (const auto& [word, count] : statistic) {
        table.push_back(Row{word, count,
                            static_cast<float>(count) * 100.f /
                                static_cast<float>(countWords)});
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
        auto freq = std::to_string(row.frequency);
        std::replace(freq.begin(), freq.end(), '.', ',');
        outFile << row.word + ";" + std::to_string(row.count) + ";" + freq;
        outFile << "\n";
    }
}
