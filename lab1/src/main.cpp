#include <iostream>
#include "BitArray.h"

using namespace std;

int main() {
    BitArray a = BitArray("1010");
    a >>= 2;
    cout << "b = " << a.to_string() << " " << a.size() << endl;

    return 0;
}