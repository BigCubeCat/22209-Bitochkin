#ifndef SOUNDPROCESSOR_TFILE_H
#define SOUNDPROCESSOR_TFILE_H

#include <string>

struct TFile {
    std::string Title;
    std::string Format;
    std::string FileName;
    bool ErrorOccurred = false;
    explicit TFile(const std::string & fileName);
};

#endif
