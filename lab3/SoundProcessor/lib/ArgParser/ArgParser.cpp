#include "ArgParser.h"

#include <iostream>

#include "TFile.h"

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
        auto file = TFile(arg);
        if (file.ErrorOccurred) {
            continue;
        }
        if (exceptConfig) {
            configFile = file;
            configExists = true;
            exceptConfig = false;
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

TFile ArgParser::getOutputFile() const {
    return outputFile;
}

std::vector<TFile> ArgParser::getInputFiles() {
    return inputFiles;
}

TFile ArgParser::getConfigFile() const {
    return configFile;
}

bool ArgParser::hasErrors() const {
    return errorsOccurred;
}

std::string ArgParser::getErrorMessage() {
    return errorMessage;
}

std::vector<std::string> ArgParser::getInputFilesString() {
    std::vector<std::string> res(inputFiles.size());
    for (int i = 0; i < inputFiles.size(); ++i) {
        res[i] = inputFiles[i].Title + "." + inputFiles[i].Format;
    }
    return res;
}

std::string ArgParser::getOutputFileString() const {
    return outputFile.Title + "." + outputFile.Format;
}

std::string ArgParser::getConfigFileString() const {
    return configFile.Title + "." + configFile.Format;
}

ArgParser::~ArgParser() = default;
