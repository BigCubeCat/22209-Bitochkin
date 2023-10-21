#ifndef SOUNDPROCESSOR_CONFIGURATOR_H
#define SOUNDPROCESSOR_CONFIGURATOR_H

#include <string>
#include <vector>

class Configurator {
public:
    explicit Configurator(std::string filename);

    ~Configurator();

    /*
     * parse();
     * Read line by line.
     * Calls parseConfigLine(line)
     */
    void parse();

    /*
     * run();
     * call parse();
     * run all convertors and write result
     */
    void run();

    /*
     * parseConfigLine(line);
     * Reads line and create Converter
     */
    void parseConfigLine(const std::string &line);

    bool hasErrors() const;

private:
    std::string fileName;

    std::string errorMessage;
    bool errorsOccurred = false;

    static std::vector<std::string> splitLine(const std::string &line);

    static bool isConvertorName(const std::string &name);

    static bool commandIsValid(const std::vector<std::string> &cmd);

};

#endif
