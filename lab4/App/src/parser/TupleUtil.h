#ifndef TUPLEUTIL_H
#define TUPLEUTIL_H

#include <sstream>
#include <stdexcept>
#include <vector>

namespace utils {
std::stringstream &operator>>(std::stringstream &stringStream,
                              std::string &string) {
  std::getline(stringStream, string);
  return stringStream;
}

template <typename... Types>
class TupleFromVectorString {
 private:
  template <typename T>
  static T stringToT(const std::string &);

  template <std::size_t... Indices>
  static std::tuple<Types...> helper(const std::vector<std::string> &,
                                     std::index_sequence<Indices...>);

 public:
  static std::tuple<Types...> makeTuple(const std::vector<std::string> &);
};

}  // namespace utils

template <typename... Types>
template <typename T>
T utils::TupleFromVectorString<Types...>::stringToT(const std::string &string) {
  T res;
  std::stringstream converting_stream;
  converting_stream.str(string);
  converting_stream >> res;
  return res;
}

template <typename... Types>
template <size_t... Indices>
std::tuple<Types...> utils::TupleFromVectorString<Types...>::helper(
    const std::vector<std::string> &v, std::index_sequence<Indices...>) {
  return std::make_tuple(stringToT<Types>(v[Indices])...);
}

template <typename... Types>
std::tuple<Types...> utils::TupleFromVectorString<Types...>::makeTuple(
    const std::vector<std::string> &v) {
  if (v.size() != sizeof...(Types)) {
    throw std::runtime_error(
        "The number of input strings does`t match "
        "the number of types: " +
        std::to_string(v.size()) + " vs " + std::to_string(sizeof...(Types)));
  }

  return helper(v, std::make_index_sequence<sizeof...(Types)>());
}

#endif
