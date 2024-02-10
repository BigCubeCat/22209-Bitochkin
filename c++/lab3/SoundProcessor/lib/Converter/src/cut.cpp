#include "cut.h"

#include <iostream>

using namespace cut;

Cut::Cut() { eh = ErrorHandler("cut"); }

bool Cut::convert(wav::SampleBuffer &currentSamples,
                  const wav::SampleBuffer &originalSamples, int sec) {
    return isWorkTime(sec);
}

bool Cut::isWorkTime(int sec) const { return !(sec >= begin && sec < end); }

void Cut::initConverter(const std::vector<std::string> &params) {
    if (params.size() < 2) {
        throw std::runtime_error("invalid parameters count");
    }
    begin = std::stoi(params[1]);
    end = std::stoi(params[2]);
}

int Cut::requiredFile() { return inputFile; }
