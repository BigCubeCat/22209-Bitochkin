#include "counter/counter.h"
#include <iostream>
#include <string>

const std::string USAGE =
    "Usage for word counter\n./word_counter input_file.txt "
    "output_file.csv\nWrite to .CSV file word frequency statistics";

int main(int argc, char *argv[]) {
  std::cout << argc << std::endl;
  if (argc != 3) {
    std::cout << USAGE << std::endl;
    return 1;
  }
  Counter *counter = new Counter(argv[1], argv[2]);
  counter->saveCSV();
  return 0;
}
