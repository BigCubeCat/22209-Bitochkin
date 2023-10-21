#include "TFile.h"

#include <algorithm>
#include <string>

TFile::TFile(const std::string &fileName) {
    std::string currentString;
    for (int i = 0; i < fileName.size(); ++i) {
        if (fileName[i] == '.') {
            Title = currentString;
            currentString = "";
        } else {
            currentString += fileName[i];
        }
    }
    std::transform(currentString.begin(), currentString.end(), currentString.begin(),
                   [](unsigned char c) { return std::tolower(c); });

    Format = currentString;
    ErrorOccurred = (Title.empty() || Format.empty());
}
