#include "noise.h"

#include <iostream>

using namespace noise;

Noise::Noise(const std::vector<std::string> &parameters) {
    begin = std::stoi(parameters[1]);
    end = std::stoi(parameters[2]);
    percent = std::stoi(parameters[3]);
}

void Noise::convert(
        std::vector<wav::SampleBuffer> &currentSamples,
        const std::vector<wav::SampleVector> &originalSamples
) {
    if (begin >= currentSamples.size()) {
        errorsOccurred = true;
        errorMessage += "Invalid begin time\n";
    }
    if (end >= currentSamples.size()) {
        errorsOccurred = true;
        errorMessage += "Invalid end time\n";
    }

    if (errorsOccurred) return;

    for (int i = begin; i <= end; i++) {
        for (int j = 0; j < wav::SAMPLES_PER_SEC; j++) {
            std::cout << "noise\n" << std::endl;
            currentSamples[i][j] -= currentSamples[i][j] * percent;
        }
    }
}
