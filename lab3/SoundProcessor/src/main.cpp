#include <iostream>
#include <vector>

#include "../../ArgParser/ArgParser.h"
#include "../../Configurator/Configurator.h"
#include "Processor/Processor.h"

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
        return 1;
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
    auto configurator = Configurator(
            parser.getConfigFileString(),
            parser.getOutputFileString(),
            parser.getInputFilesString()
    );
    if (configurator.hasErrors()) {
        std::cout << configurator.errors() << std::endl;
        printConfigError();
        return 1;
    }

    configurator.parse();

    auto proc = Processor(
            parser.getInputFilesString(),
            parser.getOutputFileString()
    );

    proc.run(configurator.getAlgorithm());

    return 0;
}


/*
 * ДОБАВИТЬ КЛАСС ErrorHandler, так как механизм обработки ошибок везде одинков
 */