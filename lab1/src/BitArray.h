#pragma once

#include <iostream>
#include <vector>

#define TYPE unsigned char

class BitArray {
private:
    size_t length = 0;
    size_t countOnes = 0;
    size_t dataSize = 0;
    std::vector<TYPE> data;
    void updateCountOnes();

public:
    BitArray();

    ~BitArray();

    explicit BitArray(size_t num_bits, unsigned long value = 0);
    explicit BitArray(std::string str);

    BitArray(const BitArray &b);

    void swap(BitArray &b);

    void resize(size_t num_bits, bool value = false);

    void clear();

    void push_back(bool bit);


    BitArray &set(size_t n, bool val = true);

    BitArray &set();

    BitArray &reset(size_t n);

    BitArray &reset();

    bool any() const;

    bool none() const;

    BitArray operator~() const;

    size_t count() const;

    bool operator[](size_t i) const;

    size_t size() const;

    bool empty() const;

    std::string to_string() const;

    BitArray &operator=(const BitArray &b);


    BitArray &operator&=(const BitArray &b);

    BitArray &operator|=(const BitArray &b);

    BitArray &operator^=(const BitArray &b);

    BitArray &operator<<=(size_t n);

    BitArray &operator>>=(size_t n);

    BitArray operator<<(size_t n) const;

    BitArray operator>>(size_t n) const;

};


bool operator==(const BitArray &a, const BitArray &b);

bool operator!=(const BitArray &a, const BitArray &b);

BitArray operator&(const BitArray &b1, const BitArray &b2);

BitArray operator|(const BitArray &b1, const BitArray &b2);

BitArray operator^(const BitArray &b1, const BitArray &b2);
