#include <iostream>

#include "BitArray.h"

using namespace std;

int main() {
    BitArray a = BitArray("1010");
    BitArray b = BitArray("000");
    a.swap(b);

    cout << "a = " << a.count() << endl;
    cout << "b = " << b.count() << endl;

    return 0;
}