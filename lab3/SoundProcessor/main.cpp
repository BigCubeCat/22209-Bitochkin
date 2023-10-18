#include <iostream>
#include <vector>

#include "ArgParser/ArgParser.h"
#include "Configurator/Configurator.h"

namespace {
    void printHelp() {
        std::cout << "Usage for SoundProcessor\n";
        std::cout << "Flag --help (-h) : show this text\n";
        std::cout << "Flag --config (-c) : set config.txt file\n";
        std::cout << "Example: \n";
        std::cout << " sound_processor [-h] [-c config.txt output.wav input1.wav [input2.wav …]]\n";
    }

    void printParserError() {
        std::cout << "Invalid arguments.\n";
        std::cout << "Use sound_processor -h for more information\n";
    }

    void printConfigError() {
        std::cout << "Invalid config.\n";
        std::cout << "Please, read README.md\n";
    }
}

int main(int argc, char *argv[]) {
    std::vector<std::string> arguments(argc);

    if (argc < 2) {
        printHelp();
        return 0;
    }
    for (int i = 1; i < argc; ++i) {
        arguments[i] = std::basic_string(argv[i]);
        if (arguments[i] == "-h" || arguments[i] == "--help") {
            printHelp();
            return 0;
        }
    }

    ArgParser parser = ArgParser(arguments);
    if (parser.hasErrors()) {
        printParserError();
        std::cout << parser.getErrorMessage();
        return 1;
    }
    Configurator configurator = Configurator(parser.getConfigFileString());
    if (configurator.hasErrors()) {
        printConfigError();
        return 1;
    }

    configurator.run();

    return 0;
}