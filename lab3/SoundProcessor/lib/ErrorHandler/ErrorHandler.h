#ifndef SOUNDPROCESSOR_ERRORHANDLER_H
#define SOUNDPROCESSOR_ERRORHANDLER_H

#include <string>
#include <vector>

class ErrorHandler {
public:
    explicit ErrorHandler(const std::string &module);

    void AddError(const std::string &message);

    bool hasErrors() const;

    std::string getErrorText();

    void printErrorText();

private:
    std::string moduleName;
    std::vector<std::string> errorMessages;
    bool errorsOccurred = false;
};


#endif