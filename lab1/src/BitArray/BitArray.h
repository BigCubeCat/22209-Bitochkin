#pragma once

#include <iostream>
#include <vector>

#define BIT_IN_INT 32

class BitArray {
private:
    int length;
    int countOnes;
    int dataSize;
    std::vector<int> data;

    int updateCountOnes();

public:
    BitArray();

    ~BitArray();

    explicit BitArray(int num_bits, unsigned long value = 0);

    BitArray(const BitArray &b);

    void swap(BitArray &b);

    BitArray &operator=(const BitArray &b);

    void resize(int num_bits, bool value = false);

    void clear();

    void push_back(bool bit);

    BitArray &operator&=(const BitArray &b);

    BitArray &operator|=(const BitArray &b);

    BitArray &operator^=(const BitArray &b);

    BitArray &operator<<=(int n);

    BitArray &operator>>=(int n);

    BitArray operator<<(int n) const;

    BitArray operator>>(int n) const;

    BitArray &set(int n, bool val = true);

    BitArray &set();

    BitArray &reset(int n);

    BitArray &reset();

    bool any() const;

    bool none() const;

    BitArray operator~() const;

    int count() const;

    bool operator[](int i) const;

    int size() const;

    bool empty() const;

    std::string to_string() const;
};
