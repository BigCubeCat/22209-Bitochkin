#include "BitArray.h"

#include <climits>
#include <iostream>

BitArray::~BitArray() = default;

/*
 * BitArray()
 * default constructor
 */
BitArray::BitArray() {
    countOnes = 0;
    length = 0;
    dataSize = length / UCHAR_WIDTH;
}

/*
 * BitArray(std::string str)
 * Initialize BitArray from string definition.
 * See BitArray::to_string()
 */
BitArray::BitArray(const std::string &str) : length(str.size()) {
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

/*
 * BitArray(size_t num_bits, unsigned long value)
 * Initialize BitArray with length and default value (0 by default)
 */
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

/*
 * BitArray(const BitArray &b);
 * Initialize BitArray from old BitArray
 */
BitArray::BitArray(const BitArray &b) {
    length = b.length;
    countOnes = b.countOnes;
    dataSize = b.dataSize;
    data = b.data;
}

/*
 * BitArray::any()
 * @return true, if count true > 0
 */
bool BitArray::any() const {
    return countOnes > 0;
}

/*
 * BitArray::none()
 * @return true, if count true is 0
 */
bool BitArray::none() const {
    return countOnes == 0;
}

/*
 * BitArray::operator~()
 * Inverts all values in BitArray
 */
BitArray BitArray::operator~() const {
    auto result = BitArray(length, 0);
    for (size_t i = 0; i < data.size(); ++i) {
        result.data[i] = ~data[i];
    }
    result.updateCountOnes();
    return result;
}

/*
 * BitArray::count()
 * @return count of true values
 */
size_t BitArray::count() const {
    return countOnes;
}

/*
 * BitArray::operator[](size_t i)
 * @return value by index
 */
bool BitArray::operator[](size_t i) const {
    if (i >= length) {
        return false;
    }
    size_t number = data[i / UCHAR_WIDTH];
    size_t bitIndex = i % UCHAR_WIDTH;
    return (number >> bitIndex) & 1;
}

/*
 * BitArray::size()
 * @return length of BitArray
 */
size_t BitArray::size() const {
    return length;
}

/*
 * BitArray::empty()
 * @return true, if length == 0
 */
bool BitArray::empty() const {
    return length == 0;
}

/*
 * BitArray::to_string()
 * @return string with 0 and 1
 */
std::string BitArray::to_string() const {
    std::string result;
    result.resize(length);
    for (size_t i = 0; i < length; ++i) {
        if ((*this)[i]) {
            result[i] = '1';
        } else {
            result[i] = '0';
        }
    }
    return result;
}

/*
 * &BitArray::set(size_t n, bool val)
 * set value by index
 */
BitArray &BitArray::set(size_t n, bool val) {
    size_t numberIndex = n / UCHAR_WIDTH;
    if ((*this)[n] == val) {
        return *this;
    }
    // Если false то отнимаем 1, если true то прибавляем
    countOnes += val ? 1 : -1;
    data[numberIndex] = data[numberIndex] | (1 << n);
    if (!val) {
        data[numberIndex] = data[numberIndex] ^ (1 << n);
    }
    return *this;
}

/*
 * &BitArray::set()
 * set all values true
 */
BitArray &BitArray::set() {
    countOnes = length;
    for (size_t i = 0; i < length; ++i) {
        set(i, true);
    }
    return *this;
}

/*
 * BitArray::push_back(bool bit)
 * Add new value to end of BitArray
 */
void BitArray::push_back(bool bit) {
    length++;
    if (length % UCHAR_WIDTH == 1) {
        dataSize += 1;
        data.push_back(bit ? 1 : 0);
        countOnes += bit ? 1 : 0;
        return;
    }
    if (bit) {
        countOnes++;
        data[dataSize - 1] |= (1 << ((length - 1) % UCHAR_WIDTH));
    }
}

/*
 * BitArray::clear()
 * Makes BitArray empty
 */
void BitArray::clear() {
    length = 0;
    data.clear();
    dataSize = 0;
    countOnes = 0;
}

/*
 * BitArray::resize(size_t num_bits, bool value)
 * Change size of BitArray.
 * If new size greater, set {value} by default
 */
void BitArray::resize(size_t num_bits, bool value) {
    if (num_bits > length) {
        for (size_t i = 0; i < length - num_bits; ++i) {
            push_back(value);
        }
    } else {
        dataSize = length / UCHAR_WIDTH + (length % UCHAR_WIDTH) ? 1 : 0;
        length = num_bits;
        data.resize(dataSize);
    }
    updateCountOnes();
}

/*
 * BitArray::updateCountOnes()
 * Recalculate count true values
 */
void BitArray::updateCountOnes() {
    countOnes = 0;
    for (size_t i = 0; i < length; ++i) {
        if ((data[length / UCHAR_WIDTH] >> i) & 1) {
            countOnes += 1;
        }
    }
}

/*
 * &BitArray::reset()
 * set all values false
 */
BitArray &BitArray::reset() {
    for (size_t i = 0; i < dataSize; ++i) {
        data[i] = 0;
    }
    countOnes = 0;
    return *this;
}

/*
 * &BitArray::reset(size_t n)
 * set single value {false}
 */
BitArray &BitArray::reset(size_t n) {
    set(n, false);
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
    return *this;
}

BitArray &BitArray::operator&=(const BitArray &b) {
    resize(std::max(dataSize, b.dataSize));
    length = std::max(length, b.length);
    for (size_t i = 0; i < data.size(); ++i) {
        data[i] &= b.data[i];
    }
    return *this;
}

BitArray &BitArray::operator^=(const BitArray &b) {
    resize(std::max(dataSize, b.dataSize));
    length = std::max(length, b.length);
    for (size_t i = 0; i < data.size(); ++i) {
        data[i] ^= b.data[i];
    }
    return *this;
}

BitArray &BitArray::operator|=(const BitArray &b) {
    resize(std::max(dataSize, b.dataSize));
    length = std::max(length, b.length);
    for (size_t i = 0; i < length; ++i) {
        data[i] |= b.data[i];
    }
    return *this;
}

BitArray &BitArray::operator<<=(size_t n) {
    for (size_t i = 0; i < n; ++i) {
        push_back(false);
    }
    return *this;
}

BitArray &BitArray::operator>>=(size_t n) {
    std::vector<unsigned char> oldData(data);
    length -= n;
    if (length % UCHAR_WIDTH == 0) {
        dataSize = length / UCHAR_WIDTH;
    } else {
        dataSize = length / UCHAR_WIDTH + 1;
    }
    data.resize(dataSize);
    for (size_t i = 0; i < length; ++i) {
        set(i, oldData[i / UCHAR_WIDTH] >> (i % UCHAR_WIDTH) & 1);
    }
    updateCountOnes();
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
    auto result = BitArray(b1);
    result &= b2;
    return result;
}

BitArray operator|(const BitArray &b1, const BitArray &b2) {
    auto result = BitArray(b1);
    result |= b2;
    return result;
}

BitArray operator^(const BitArray &b1, const BitArray &b2) {
    auto result = BitArray(b1);
    result ^= b2;
    return result;
}
