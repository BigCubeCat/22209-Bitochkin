#ifndef TUPLEPRINT_H
#define TUPLEPRINT_H

#include <tuple>

namespace utils {
    template<size_t Iter>
    struct TuplePrinter {
        template<typename OutStream, typename Tuple>
        static void print(OutStream &outStream, Tuple &tuple, const std::string &end = " ") {
            outStream << std::get < std::tuple_size_v < Tuple > -Iter > (tuple) << end;
            TuplePrinter<Iter - 1>::print(outStream, tuple);
        }
    };

    template<>
    struct TuplePrinter<0ull> {
        template<typename OutStream, typename Tuple>
        static void print(OutStream &outStream, Tuple &tuple, const std::string &end = " ") {}
    };
}


template<typename CharT, typename Traits, typename ...Args>
auto &operator<<(std::basic_ostream <CharT, Traits> &outStream, const std::tuple<Args...> &tuple) {
    utils::TuplePrinter<sizeof...(Args)>::print(outStream, tuple);
    return outStream;
}

#endif
