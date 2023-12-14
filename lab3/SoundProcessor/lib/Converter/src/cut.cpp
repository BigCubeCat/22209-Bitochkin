#include "cut.h"

#include <iostream>

using namespace cut;

Cut::Cut(const std::vector<std::string> &parameters) {
    if (parameters.size() < 2) {
        throw std::runtime_error("invalid parameters count");
    }
    begin = std::stoi(parameters[1]);
    end = std::stoi(parameters[2]);
    eh = ErrorHandler("cut");
}

void Cut::convert(
        wav::SampleBuffer *currentSamples,
        wav::SampleBuffer *originalSamples,
        int sec
) {
    if (sec >= begin && sec <= end) {
        currentSamples = nullptr;
    }
    currentSamples = currentSamples;
}