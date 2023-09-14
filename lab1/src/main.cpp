#include <iostream>

#include "BitArray.h"

using namespace std;


int main() {
    // Без этого не работает(


    auto ba = BitArray(5, 8);
    cout << ba.to_string() << endl;

}