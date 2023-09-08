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
    void updateCountOnes();

public:
    BitArray();

    ~BitArray();

    explicit BitArray(int num_bits, unsigned long value = 0);

    BitArray(const BitArray &b);

    void swap(BitArray &b);


    void resize(int num_bits, bool value = false);

    void clear();

    void push_back(bool bit);


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

    BitArray &operator=(const BitArray &b);


    BitArray &operator&=(const BitArray &b);

    BitArray &operator|=(const BitArray &b);

    BitArray &operator^=(const BitArray &b);

    BitArray &operator<<=(int n);

    BitArray &operator>>=(int n);

    BitArray operator<<(int n) const;

    BitArray operator>>(int n) const;

};


bool operator==(const BitArray &a, const BitArray &b);

bool operator!=(const BitArray &a, const BitArray &b);

BitArray operator&(const BitArray &b1, const BitArray &b2);

BitArray operator|(const BitArray &b1, const BitArray &b2);

BitArray operator^(const BitArray &b1, const BitArray &b2);
