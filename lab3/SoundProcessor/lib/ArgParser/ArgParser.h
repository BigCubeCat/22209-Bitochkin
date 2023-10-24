#ifndef SOUNDPROCESSOR_ARGPARSER_H
#define SOUNDPROCESSOR_ARGPARSER_H

#include <vector>
#include <string>

#include "TFile.h"

class ArgParser {
public:
    ArgParser(const std::vector<std::string>& arguments);

    TFile getOutputFile() const;

    std::vector<TFile> getInputFiles();

    TFile getConfigFile() const;

    std::string getConfigFileString() const;
    std::vector<std::string> getInputFilesString();
    std::string getOutputFileString() const;

    bool hasErrors() const;

    std::string getErrorMessage();

    ~ArgParser();

private:
    TFile configFile = TFile("");
    std::vector<TFile> inputFiles;
    TFile outputFile = TFile("");

    std::string errorMessage;
    bool errorsOccurred = false;
};


#endif
