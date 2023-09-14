#include "BitArray.h"

#include <climits>

#include "utils.h"

BitArray::~BitArray() {
    clear();
}

BitArray::BitArray() {
    countOnes = 0;
    length = 64;
    dataSize = length / UCHAR_WIDTH;
    for (size_t i = 0; i < dataSize; ++i) {
        data.push_back(0);
    }
}

BitArray::BitArray(std::string str) : length(str.size()) {
    if (length % UCHAR_WIDTH == 0) {
        dataSize = length / UCHAR_WIDTH;
    } else {
        dataSize = length / UCHAR_WIDTH + 1;
    }
    data.resize(dataSize);
    for (size_t i = 0; i < length; ++i) {
        set(i, str[i] == '1');
    }
}

BitArray::BitArray(size_t num_bits, unsigned long value) : length(num_bits) {
    if (length % UCHAR_WIDTH == 0) {
        dataSize = length / UCHAR_WIDTH;
    } else {
        dataSize = length / UCHAR_WIDTH + 1;
    }
    for (size_t i = 0; i < dataSize; ++i) {
        size_t num = 0;
        for (size_t j = 0; j < UCHAR_WIDTH; ++j) {
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
    std::string string = to_string();
    for (size_t i = 0; i < string.size(); ++i) {
        string[i] = (string[i] == '1') ? '0' : '1';
    }
    return BitArray(string);
}

size_t BitArray::count() const {
    return countOnes;
}

bool BitArray::operator[](size_t i) const {
    if (i >= length) {
        return false;
    }
    size_t number = data[i / UCHAR_WIDTH];
    size_t bitIndex = i % UCHAR_WIDTH;
    return (number >> bitIndex) & 1;
}

size_t BitArray::size() const {
    return length;
}

bool BitArray::empty() const {
    return length == 0;
}

std::string BitArray::to_string() const {
    std::string result;
    for (size_t i = 0; i < length; ++i) {
        if ((*this)[i]) {
            result += '1';
        } else {
            result += '0';
        }
    }
    return result;
}

BitArray &BitArray::set(size_t n, bool val) {
    size_t numberIndex = n / UCHAR_WIDTH;
    data[numberIndex] = data[numberIndex] | (1 << n);
    if (!val) {
        data[numberIndex] = data[numberIndex] ^ (1 << n);
    }
    return *this;
}

BitArray &BitArray::set() {
    for (size_t i = 0; i < length; ++i) {
        set(i, true);
    }
    return *this;
}

void BitArray::push_back(bool bit) {
    length++;
    if (length % UCHAR_WIDTH == 1) {
        dataSize += 1;
        data.push_back(bit ? 1 : 0);
        countOnes += 1;
        return;
    }
    if (bit) {
        countOnes += 1;
        countOnes += 1;
        data[dataSize - 1] |= (1 << ((length - 1) % UCHAR_WIDTH));
    }
}

void BitArray::clear() {
    length = 0;
    data.clear();
    dataSize = 0;
    countOnes = 0;
}

void BitArray::resize(size_t num_bits, bool value) {
    if (num_bits > length) {
        for (size_t i = 0; i < length - num_bits; ++i) {
            this->push_back(value);
        }
    } else {
        dataSize = length / UCHAR_WIDTH + (length % UCHAR_WIDTH) ? 1 : 0;
        length = num_bits;
        data.resize(dataSize);
    }
    updateCountOnes();
}

void BitArray::updateCountOnes() {
    countOnes = 0;
    for (size_t i = 0; i < length; ++i) {
        if ((data[length / UCHAR_WIDTH] >> i) & 1) {
            countOnes += 1;
        }
    }
}

BitArray &BitArray::reset() {
    for (size_t i = 0; i < dataSize; ++i) {
        data[i] = 0;
    }
    countOnes = 0;
    return *this;
}

BitArray &BitArray::reset(size_t n) {
    data[length / n] = data[length / n] & ~(1 << n);
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
    this->resize(std::max(dataSize, b.dataSize));
    for (size_t i = 0; i < dataSize; ++i) {
        data[i] &= b.data[i];
    }
    return *this;
}

BitArray &BitArray::operator^=(const BitArray &b) {
    this->resize(std::max(dataSize, b.dataSize));
    for (size_t i = 0; i < dataSize; ++i) {
        data[i] ^= b.data[i];
    }
    return *this;
}

BitArray &BitArray::operator|=(const BitArray &b) {
    this->resize(std::max(dataSize, b.dataSize));
    for (size_t i = 0; i < dataSize; ++i) {
        data[i] |= b.data[i];
    }
    return *this;
}

BitArray &BitArray::operator<<=(size_t n) {
    for (size_t i = 0; i < n; ++i) {
        push_back(false);
        std::cout << to_string() << std::endl;
    }
    return *this;
}

BitArray &BitArray::operator>>=(size_t n) {
    std::vector<TYPE> oldData(data);
    length -= n;
    if (length % UCHAR_WIDTH == 0) {
        dataSize = length / UCHAR_WIDTH;
    } else {
        dataSize = length / UCHAR_WIDTH + 1;
    }
    data.resize(dataSize);
    for (size_t i = 0; i < length; ++i) {
        set(i, oldData[i / UCHAR_WIDTH] >> (i % UCHAR_WIDTH) & 1);
        std::cout << i << " "
                  << (oldData[i / UCHAR_WIDTH] >> (i % UCHAR_WIDTH) & 1)
                  << '\n';
        1;
    }
    std::cout << "new value = " << to_string() << std::endl;
    return *this;
}

BitArray BitArray::operator<<(size_t n) const {
    auto newValue = BitArray(*this);
    newValue <<= n;
    return newValue;
}

BitArray BitArray::operator>>(size_t n) const {
    BitArray newBitArray = BitArray(*this);
    newBitArray >>= n;
    return newBitArray;
}

bool operator==(const BitArray &a, const BitArray &b) {
    if (a.size() != b.size()) {
        return false;
    }
    if (a.count() != b.count()) {
        return false;
    }
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

bool operator!=(const BitArray &a, const BitArray &b) {
    return !(a == b);
}
BitArray operator&(const BitArray &b1, const BitArray &b2) {
    auto result = BitArray((size_t)std::max(b1.size(), b2.size()), 0);
    for (size_t i = 0; i < result.size(); ++i) {
        result.set(i, b1[i] && b2[i]);
    }
    return result;
}

BitArray operator|(const BitArray &b1, const BitArray &b2) {
    auto result = BitArray((size_t)std::max(b1.size(), b2.size()), 0);
    for (size_t i = 0; i < result.size(); ++i) {
        result.set(i, b1[i] || b2[i]);
    }
    return result;
}

BitArray operator^(const BitArray &b1, const BitArray &b2) {
    auto result = BitArray((size_t)std::max(b1.size(), b2.size()), 0);
    for (size_t i = 0; i < result.size(); ++i) {
        result.set(i, b1[i] != b2[i]);
    }
    return result;
}
