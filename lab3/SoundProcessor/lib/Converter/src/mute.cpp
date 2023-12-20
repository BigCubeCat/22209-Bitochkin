#include "mute.h"

#include <iostream>

using namespace mute;

Mute::Mute() { eh = ErrorHandler("mute"); }

bool Mute::convert(wav::SampleBuffer *currentSamples,
                   wav::SampleBuffer &originalSamples, int sec) {
    if (currentSamples == nullptr) {
        throw std::invalid_argument("invalid sample.");
    }
    if (isWorkTime(sec)) {
        for (int j = 0; j < wav::SAMPLES_PER_SEC; j++) {
            (*currentSamples)[j] = 0;
        }
    }
    return true;
}

bool Mute::isWorkTime(int sec) const { return (sec >= start && sec < end); }

void Mute::initConverter(const std::vector<std::string> &params) {
    if (params.size() < 2) {
        throw std::runtime_error("invalid parameters count");
    }
    start = std::stoi(params[1]);
    end = std::stoi(params[2]);
}

int Mute::requiredFile() { return inputFile; }
