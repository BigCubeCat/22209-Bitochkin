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

    ~ArgParser();

private:
    TFile configFile = TFile("");
    std::vector<TFile> inputFiles;
    TFile outputFile = TFile("");

    bool errorsOccurred = false;
};


#endif
