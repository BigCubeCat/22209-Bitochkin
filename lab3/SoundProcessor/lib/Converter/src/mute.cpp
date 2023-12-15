#include <iostream>
#include "mute.h"

using namespace mute;

Mute::Mute(const std::vector<std::string> &parameters) {
    if (parameters.size() < 2) {
        throw std::runtime_error("invalid parameters count");
    }
    start = std::stoi(parameters[1]);
    end = std::stoi(parameters[2]);
    eh = ErrorHandler("mute");
}

bool Mute::convert(
        wav::SampleBuffer *currentSamples,
        wav::SampleBuffer *originalSamples,
        int sec
) {
    if (sec >= start && sec < end) {
        for (int j = 0; j < wav::SAMPLES_PER_SEC; j++) {
            (*currentSamples)[j] = 0;
        }
    }
    return true;
}
