#ifndef SOUNDPROCESSOR_ARGPARSER_H
#define SOUNDPROCESSOR_ARGPARSER_H

#include <string>
#include <vector>

class ArgParser {
   public:
    ArgParser(const std::vector<std::string> &arguments);

    std::string getConfigFile() const;

    std::vector<std::string> getInputFiles();

    std::string getOutputFile() const;

    bool hasErrors() const;

    std::string getErrorMessage();

    ~ArgParser();

   private:
    std::string configFile;
    std::vector<std::string> inputFiles;
    std::string outputFile;

    std::string errorMessage;
    bool errorsOccurred = false;
};

#endif
