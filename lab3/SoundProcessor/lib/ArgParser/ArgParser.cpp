#include "ArgParser.h"

ArgParser::ArgParser(const std::vector<std::string> &arguments) {
    bool exceptConfig = false;
    bool configExists = false;
    bool outputExists = false;
    bool inputNotEmpty = false;
    for (const auto &arg: arguments) {
        if (arg == "-c" || arg == "--config") {
            exceptConfig = true;
            continue;
        }
        if (arg.empty()) {
            continue;
        }
        if (exceptConfig) {
            configFile = arg;
            configExists = true;
            exceptConfig = false;
        } else {
            if (!outputExists) {
                outputFile = arg;
                outputExists = true;
            } else {
                inputFiles.push_back(arg);
                inputNotEmpty = true;
            }
        }
    }
    errorsOccurred = !(configExists && outputExists && inputNotEmpty);
    if (errorsOccurred) {
        if (!configExists) {
            errorMessage += "Config file not specified\n";
        }
        if (!outputExists) {
            errorMessage += "No output file\n";
        }
        if (!inputNotEmpty) {
            errorMessage += "No input files\n";
        }
    }
}

bool ArgParser::hasErrors() const {
    return errorsOccurred;
}

std::string ArgParser::getErrorMessage() {
    return errorMessage;
}

std::vector<std::string> ArgParser::getInputFiles() {
    std::vector<std::string> res(inputFiles.size());
    for (int i = 0; i < inputFiles.size(); ++i) {
        res[i] = inputFiles[i];
    }
    return res;
}

std::string ArgParser::getOutputFile() const {
    return outputFile;
}

std::string ArgParser::getConfigFile() const {
    return configFile;
}

ArgParser::~ArgParser() = default;
