#include "utils.h"


std::string binaryString(int number, int bitSize) {
    std::string result = "";
    while (number > 0) {
        result += (number % 2 == 0) ? '0' : '1';
        number /= 2;
    }
    while (result.size() < bitSize) {
        result += '0';
    }
    return result;
}
