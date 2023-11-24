#include <iostream>

#include "parser/TuplePrint.h"
#include "parser/parser.h"

using namespace std;

int main(int argc, char **argv) {
  std::string filename = argv[1];
  CSVParser<int, string, string, string, string, string, string, string, string>
      parser(filename, 1, '\n', '"', ',');
  for (auto t : parser) {
    cout << t << endl;
  }

  return 0;
}
