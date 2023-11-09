#include "ErrorHandler.h"

#include <iostream>

ErrorHandler::ErrorHandler(const std::string &module) : moduleName(module) {
    errorMessages.clear();
}

void ErrorHandler::AddError(const std::string &message) {
    errorsOccurred = true;
    errorMessages.push_back(message);
}

bool ErrorHandler::hasErrors() const {
    return errorsOccurred;
}

std::string ErrorHandler::getErrorText() {
    std::string result = "error occurred at module " + moduleName + "\n";
    for (int i = 0; i < errorMessages.size(); ++i) {
        result += "\t\t" + errorMessages[i] + "\n";
    }
    return result;
}

void ErrorHandler::printErrorText() {
    std::cout << getErrorText() << std::endl;
}
