#ifndef SOUNDPROCESSOR_CONFIGURATOR_H
#define SOUNDPROCESSOR_CONFIGURATOR_H

#include <string>
#include <vector>
#include <map>

class Configurator {
public:
    explicit Configurator(
            const std::string &configFile,
            const std::string &outFile,
            const std::vector<std::string> &inputFiles
    );

    ~Configurator();

    /*
     * parse();
     * Read line by line.
     * Calls parseConfigLine(line)
     */
    void parse();

    /*
     * parseConfigLine(line);
     * Reads line and create Converter
     */
    void parseConfigLine(const std::string &line, int lineNumber);

    bool hasErrors() const;

    std::string errors() const;

    std::vector<std::vector<std::string >> getAlgorithm();

private:
    std::vector<std::vector<std::string >> algorithm;

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

    std::map<std::string, bool> commandMap = {};

};

#endif
