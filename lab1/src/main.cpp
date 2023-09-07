#include <iostream>
#include "BitArray.h"

using namespace std;

int main() {
    auto ba = new BitArray(33);
    ba->set(5, true);
    ba->set(6, true);
    ba->set(7, true);
    cout << ba->to_string() << endl;

    ba->set(6, false);
    cout << ba->to_string() << endl;

    ba->set();
    cout << ba->to_string() << endl;

    return 0;
}