#include "mute.h"

using namespace mute;

Mute::Mute(const std::vector<std::string>& parameters) {
    start = std::stoi(parameters[1]);
    end = std::stoi(parameters[2]);
}

void Mute::convert(std::vector<wav::SampleBuffer> &currentSamples,
                   const std::vector<wav::SampleVector> &originalSamples) {
    if (start >= currentSamples.size()) throw converter::WrongTime(start);
    if (end >= currentSamples.size()) throw converter::WrongTime(end);

    for (int i = start; i <= end; i++) {
        for (int j = 0; j < wav::SAMPLES_PER_SEC; j++) {
            currentSamples[i][j] = 0;
        }
    }
}
