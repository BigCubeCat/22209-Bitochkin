#ifndef PARSER_H
#define PARSER_H

#include <tuple>
#include <stdexcept>
#include <optional>
#include <vector>
#include <algorithm>

#include "./TupleUtil.h"
#include "./IFStream.h"

template<typename ...Types>
class CSVParser {

private:
    utils::IFStream inputFile;
    std::size_t currentLineNum;
    char lineDelimiter;
    char cellDelimiter;
    char escapingChar;

    std::vector<std::string> getCells(const std::string &);

public:
    explicit CSVParser(const std::string &, size_t = 0, char= '\n', char= '"', char= ',');

    std::optional<std::tuple<Types...>> getRecord();

    class Iterator {
    private:
        CSVParser *csvParser;
        std::optional<std::tuple<Types...>> _record;
        size_t lineNumber;
    public:
        Iterator();

        explicit Iterator(CSVParser &);

        std::tuple<Types...> operator*();

        Iterator &operator++();

        bool operator!=(const Iterator &);
    };

    Iterator begin();

    Iterator end();

    void setLineDelimiter(char);

    void setCellDelimiter(char);

    void setEscapingChar(char);


};

template<typename... Types>
CSVParser<Types...>::Iterator::Iterator(CSVParser &parser): csvParser(&parser), _record(parser.getRecord()),
                                                            lineNumber(parser.currentLineNum) {
    if (!_record) {
        csvParser = nullptr;
        lineNumber = 0ull;
    }
}

template<typename... Types>
std::tuple<Types...> CSVParser<Types...>::Iterator::operator*() {
    return *_record;
}

template<typename... Types>
CSVParser<Types...>::Iterator::Iterator(): csvParser(nullptr), _record({}), lineNumber(0ull) {}

template<typename... Types>
typename CSVParser<Types...>::Iterator &CSVParser<Types...>::Iterator::operator++() {
    _record = csvParser->getRecord();
    if (!_record) {
        csvParser = nullptr;
        lineNumber = 0ull;
    }

    return *this;
}

template<typename... Types>
bool CSVParser<Types...>::Iterator::operator!=(const CSVParser::Iterator &other) {
    return other.csvParser != csvParser ||
           other.lineNumber != lineNumber ||
           other._record.has_value() != _record.has_value();
}

template<typename... Types>
CSVParser<Types...>::CSVParser(
        const std::string &filename,
        size_t skip,
        char line_delimiter,
        char escaping_char,
        char cell_delimiter
):
        inputFile(filename),
        currentLineNum(skip),
        lineDelimiter(line_delimiter),
        cellDelimiter(cell_delimiter),
        escapingChar(escaping_char) {
    if (!inputFile.is_open()) {
        throw std::runtime_error("Cant open file: " + filename);
    }
    std::string unused_line;
    for (size_t i = 0; i < skip; ++i) {
        inputFile.getLine(unused_line, lineDelimiter, lineDelimiter);
    }
}

template<typename... Types>
std::optional<std::tuple<Types...>> CSVParser<Types...>::getRecord() {
    std::string line;
    if (!inputFile.getLine(line, lineDelimiter, lineDelimiter)) {
        return {};
    }
    ++currentLineNum;
    auto cells = getCells(line);
    if (cells.size() != sizeof...(Types)) {
        throw std::runtime_error("In line " + std::to_string(currentLineNum) + " incorrect number of cells: " +
                                 std::to_string(cells.size()));
    }
    return {utils::TupleFromVectorString<Types...>::makeTuple(cells)};
}

template<typename... Types>
std::vector<std::string> CSVParser<Types...>::getCells(const std::string &line) {
    std::vector<std::string> res;
    for (auto it = line.cbegin(); it != line.cend();) {
        std::string cell;
        it = utils::IFStream::getLine(it, line.cend(), cell, cellDelimiter, escapingChar);
        cell.erase(std::remove(cell.begin(), cell.end(), escapingChar), cell.end());
        res.push_back(std::move(cell));
    }
    return res;
}

template<typename... Types>
typename CSVParser<Types...>::Iterator CSVParser<Types...>::begin() {
    return Iterator(*this);
}

template<typename... Types>
typename CSVParser<Types...>::Iterator CSVParser<Types...>::end() {
    return Iterator();
}

template<typename... Types>
void CSVParser<Types...>::setLineDelimiter(char delimiter) {
    lineDelimiter = delimiter;
}

template<typename... Types>
void CSVParser<Types...>::setCellDelimiter(char delimiter) {
    cellDelimiter = delimiter;
}

template<typename... Types>
void CSVParser<Types...>::setEscapingChar(char esc_char) {
    escapingChar = esc_char;
}

#endif
