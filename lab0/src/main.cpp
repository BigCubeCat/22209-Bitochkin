#include <iostream>
#include <string>

#include "counter/counter.h"

const std::string USAGE =
    "Usage for word counter\n./word_counter input_file.txt "
    "output_file.csv\nWrite to .CSV file word frequency statistics";

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << USAGE << std::endl;
        return 1;
    }
    Counter counter = Counter(argv[1], argv[2]);
    counter.saveCSV();
    return 0;
}
