#include "noise.h"

#include <iostream>

using namespace noise;

Noise::Noise(const std::vector<std::string> &parameters) {
    start = std::stoi(parameters[1]);
    end = std::stoi(parameters[2]);
    percent = std::stoi(parameters[3]);
}

void Noise::convert(
        std::vector<wav::SampleBuffer> &currentSamples,
        const std::vector<wav::SampleVector> &originalSamples
) {
    if (start >= currentSamples.size()) throw converter::WrongTime(start);
    if (end >= currentSamples.size()) throw converter::WrongTime(end);

    for (int i = start; i <= end; i++) {
        for (int j = 0; j < wav::SAMPLES_PER_SEC; j++) {
            currentSamples[i][j] -= currentSamples[i][j] * percent;
        }
    }
}
