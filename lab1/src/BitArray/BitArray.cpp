#include "BitArray.h"
#include "utils.h"

#include <limits.h>


BitArray::~BitArray() {}

BitArray::BitArray() {
    countOnes = 0;
    length = 64;
    dataSize = length / BIT_IN_INT;
    for (int i = 0; i < dataSize; ++i) {
        data.push_back(0);
    }
}

BitArray::BitArray(int num_bits, unsigned long value) {
    length = num_bits;
    if (length % BIT_IN_INT == 0) {
        dataSize = length / BIT_IN_INT;
    } else {
        dataSize = length / BIT_IN_INT + 1;
    }
    for (int i = 0; i < dataSize; ++i) {
        data.push_back(0);
    }
}

BitArray::BitArray(const BitArray &b) {
    length = b.length;
    countOnes = b.countOnes;
    dataSize = b.dataSize;
    data = b.data;
}

bool BitArray::any() const {
    return countOnes > 0;
}

bool BitArray::none() const {
    return countOnes == 0;
}

BitArray BitArray::operator~() const {
    return BitArray();
}

int BitArray::count() const {
    return countOnes;
}

bool BitArray::operator[](int i) const {
    int number = data[i / BIT_IN_INT];
    int bitIndex = i % BIT_IN_INT;
    return (number >> bitIndex) & 1;
}

int BitArray::size() const {
    return length;
}

bool BitArray::empty() const {
    return length == 0;
}

std::string BitArray::to_string() const {
    std::string result;
    int lastSize = length % BIT_IN_INT;
    int lastIndex = data.size() - 1;
    for (int i = 0; i < data.size(); i++) {
        result += binaryString(data[i], (i == lastIndex) ? lastSize : BIT_IN_INT);
    }
    return result;
}

BitArray &BitArray::set(int n, bool val) {
    int numberIndex = n / BIT_IN_INT;
    data[numberIndex] = data[numberIndex] | (1 << n);
    if (!val) {
        data[numberIndex] = data[numberIndex] ^ (1 << n);
    }
    return *this;
}

BitArray &BitArray::set() {
    for (int i = 0; i < data.size(); ++i) {
        data[i] = INT_MAX;
    }
    return *this;
}

