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
        int num = 0;
        for (int j = 0; j < BIT_IN_INT; ++j) {
            if (value % 2 == 1) {
                countOnes++;
                num |= (1 << j);
            }
            value /= 2;
        }
        data.push_back(num);
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
        data[i] = ~INT_MIN;
    }
    return *this;
}

void BitArray::push_back(bool bit) {
    length++;
    if (length % BIT_IN_INT == 1) {
        dataSize += 1;
        data.push_back(bit ? 1 : 0);
        countOnes += 1;
        return;
    }
    if (bit) {
        countOnes += 1;
        data[dataSize - 1] |= (1 << ((length - 1) % BIT_IN_INT));
    }
    countOnes += bit ? 1 : 0;
}

void BitArray::clear() {
    length = 0;
    data.clear();
    dataSize = 0;
    countOnes = 0;
}

void BitArray::resize(int num_bits, bool value) {
    if (num_bits > length) {
        for (int i = 0; i < length - num_bits; ++i) {
            this->push_back(value);
        }
    } else {
        dataSize = length / BIT_IN_INT + (length % BIT_IN_INT) ? 1 : 0;
        length = num_bits;
        data.resize(dataSize);
    }
    updateCountOnes();
}

void BitArray::updateCountOnes() {
    countOnes = 0;
    for (int i = 0; i < length; ++i) {
        if ((data[length / BIT_IN_INT] >> i) & 1) {
            countOnes += 1;
        }
    }
}

BitArray &BitArray::reset() {
    for (int i = 0; i < dataSize; ++i) {
        data[i] = 0;
    }
    countOnes = 0;
    return *this;
}

BitArray &BitArray::reset(int n) {
    data[length / n] = data[length / n]  & ~(1 << n);
    return *this;
}

void BitArray::swap(BitArray &b) {
    std::swap(b.length, length);
    std::swap(b.dataSize, dataSize);
    std::swap(b.countOnes, countOnes);
    data.swap(b.data);
}

BitArray &BitArray::operator=(const BitArray &b) {
    length = b.length;
    dataSize = b.dataSize;
    data = b.data;
    countOnes = b.countOnes;
}

BitArray &BitArray::operator&=(const BitArray &b) {
    for (int i = 0; i < std::min(dataSize, b.dataSize); ++i) {
        data[i] &= b.data[i];
    }
    return *this;
}

BitArray &BitArray::operator^=(const BitArray &b) {
    if (length < b.length) {
        resize(b.length);
    }
    for (int i = 0; i < dataSize, b.dataSize; ++i) {
        data[i] ^= b.data[i];
    }
    return *this;
}

BitArray &BitArray::operator|=(const BitArray &b) {
    // TODO resize
    if (length < b.length) {
        resize(b.length);
    }
    for (int i = 0; i < std::max(dataSize, b.dataSize); ++i) {
        data[i] &= b.data[i];
    }
    return *this;
}

bool operator==(const BitArray &a, const BitArray &b) {
    if (a.size() != b.size()) {
        return false;
    }
    if (a.count() !=  b.count()) {
        return false;
    }
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

bool operator!=(const BitArray &a, const BitArray &b) {
    return !(a == b);
}

