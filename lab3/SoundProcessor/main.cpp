#include <iterator>
#include <iostream>
#include <vector>

void printHelp() {
    std::cout << "Usage for SoundProcessor\n";
    std::cout << "Flag --help (-h) : show this text\n";
    std::cout << "Flag --config (-c) : set config.txt file\n";
    std::cout << "Example: \n";
    std::cout << " sound_processor [-h] [-c config.txt output.wav input1.wav [input2.wav …]]\n";
}

int main(int argc, char *argv[]) {
    std::vector<std::string> arguments(argc);

    if (argc < 2) {
        printHelp();
        return 0;
    }
    for (int i = 0; i < argc; ++i) {
        arguments[i] = std::basic_string(argv[i]);
        if (arguments[i] == "-h" || arguments[i] == "--help") {
            printHelp();
            return 0;
        }
    }
    return 0;
}