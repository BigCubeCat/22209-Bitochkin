#include <iostream>

#include "BitArray.h"

using namespace std;



int main() {
    auto first = BitArray("101");
    auto second = BitArray(3, 5);
    auto copy = BitArray(first);
    std::cout << first.to_string() << std::endl;
    std::cout << second.to_string() << std::endl;
    std::cout << copy.to_string() << std::endl;

    auto ba = BitArray("1001");
    cout << ba.count() << endl;
}