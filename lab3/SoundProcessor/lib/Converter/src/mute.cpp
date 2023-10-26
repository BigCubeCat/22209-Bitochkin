#include "mute.h"

using namespace mute;

Mute::Mute(const std::vector<std::string>& parameters) {
    begin = std::stoi(parameters[1]);
    end = std::stoi(parameters[2]);
}

void Mute::convert(std::vector<wav::SampleBuffer> &currentSamples,
                   const std::vector<wav::SampleVector> &originalSamples) {
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
            currentSamples[i][j] = 0;
        }
    }
}
