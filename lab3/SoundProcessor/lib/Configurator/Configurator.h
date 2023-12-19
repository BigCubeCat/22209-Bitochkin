#ifndef SOUNDPROCESSOR_CONFIGURATOR_H
#define SOUNDPROCESSOR_CONFIGURATOR_H

#include <string>
#include <vector>
#include <set>
#include "ConverterConfig.h"

class Configurator {
public:
    explicit Configurator(
            const std::string &configFile,
            const std::string &outFile,
            const std::vector<std::string> &inputFiles
    );

    ~Configurator();

    bool hasErrors() const;

    std::string errors() const;

    std::vector<ConverterConfig> getAlgorithm();

private:
    /*
     * parseConfigLine(line);
     * Reads line and create Converter
     */
    void parseConfigLine(const std::string &line, int lineNumber);

    /*
     * parse();
     * Read line by line.
     * Calls parseConfigLine(line)
     */
    void parse();


    std::vector<ConverterConfig> algorithm;

    std::string config;
    std::string out;
    std::vector<std::string> input;

    std::string errorMessage;
    bool errorsOccurred = false;

    static std::vector<std::string> splitLine(const std::string &line);

    bool isConvertorName(const std::string &name);

    static bool commandIsValid(const std::vector<std::string> &cmd);

    static bool linkIsValid(const std::string &link);

    static bool isNumber(const std::string &num);

    std::set<std::string> commandSet = {"mix", "mute", "noise", "cut", "crop"};

};

#endif
