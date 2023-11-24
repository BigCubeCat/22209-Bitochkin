#ifndef IFSTREAM_H
#define IFSTREAM_H

#include <fstream>
#include <string>

namespace utils {
class IFStream : public std::ifstream {
 public:
  template <class InputIterator>
  static InputIterator getLine(InputIterator, InputIterator, std::string &,
                               char, char);

  basic_istream &getLine(std::string &, char, char);

  explicit IFStream(const std::string &);

  ~IFStream() override = default;
};

template <typename InputIterator>
InputIterator IFStream::getLine(InputIterator begin, InputIterator end,
                                std::string &result, char delimiterChar,
                                char escapingChar) {
  result.clear();

  auto it = begin;
  bool isEscaping = false;

  while (it != end && (*it != delimiterChar || isEscaping)) {
    if (*it == escapingChar) {
      isEscaping = !isEscaping;
    }
    result.push_back(*it);
    ++it;
  }
  if (it != end) {
    ++it;
  }
  return it;
}

std::basic_istream<char, std::char_traits<char>> &IFStream::getLine(
    std::string &result, char delimiterChar, char escapingChar) {
  auto begin = std::istreambuf_iterator<char>(*this);
  auto end = std::istreambuf_iterator<char>();

  if (begin == end) {
    return std::getline(*this, result);
  }
  getLine(begin, end, result, delimiterChar, escapingChar);

  return *this;
}

IFStream::IFStream(const std::string &fileName) : std::ifstream(fileName) {}

}  // namespace utils

#endif
