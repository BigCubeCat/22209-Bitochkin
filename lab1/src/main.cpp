#include <iostream>
#include "BitArray.h"

using namespace std;

int main() {
    BitArray a = BitArray("1010");
    a.push_back(false);
    cout << a.to_string() << endl;
    a.push_back(false);
    a.push_back(false);
    a.push_back(false);
    cout << "b = " << a.to_string() << " " << a.size() << endl;

    return 0;
}