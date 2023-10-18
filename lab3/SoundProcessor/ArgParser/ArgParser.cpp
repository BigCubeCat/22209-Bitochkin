#include "ArgParser.h"

#include "TFile.h"

ArgParser::ArgParser(const std::vector<std::string> &arguments) {
    bool exceptConfig = false;
    bool configExists = false;
    bool outputExists = false;
    bool inputNotEmpty = false;
    for (const auto & arg : arguments) {
        if (arg == "-c" || arg == "--config") {
            exceptConfig = true;
        }
        auto file = TFile(arg);
        if (file.ErrorOccurred) {
            continue;
        }
        if (exceptConfig) {
            configFile = file;
            configExists = true;
        } else {
            if (!outputExists) {
                outputFile = file;
                outputExists = true;
            } else {
                inputFiles.push_back(file);
                inputNotEmpty = true;
            }
        }
    }
    errorsOccurred = !(exceptConfig && configExists && outputExists && inputNotEmpty);
}

TFile ArgParser::getOutputFile() const {
    return outputFile;
}

std::vector<TFile> ArgParser::getInputFiles() {
    return inputFiles;
}

TFile ArgParser::getConfigFile() const {
    return configFile;
}

ArgParser::~ArgParser() = default;
