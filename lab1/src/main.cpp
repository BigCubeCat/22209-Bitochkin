#include <iostream>
#include "BitArray.h"

using namespace std;

int main() {
    auto ba = new BitArray(32, 5);
    cout << ba->to_string() << endl;

    ba->push_back(1);

    cout << ba->to_string() << endl;

    return 0;
}