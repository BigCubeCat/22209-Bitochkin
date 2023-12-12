#include "mute.h"

using namespace mute;

Mute::Mute(const std::vector<std::string> &parameters) {
    if (parameters.size() < 2) {
        throw std::runtime_error("invalid parameters count");
    }
    start = std::stoi(parameters[0]);
    end = std::stoi(parameters[1]);
    this->eh = new ErrorHandler("mute");
}

void Mute::convert(std::vector<wav::SampleBuffer> &currentSamples,
                   const std::vector<wav::SampleVector> originalSamples) {
    if (start >= currentSamples.size()) {
        eh->AddError("wrong start format");
        return;
    }
    if (end >= currentSamples.size()) {
        eh->AddError("wrong end format");
        return;
    }

    for (int i = start; i <= end; i++) {
        for (int j = 0; j < wav::SAMPLES_PER_SEC; j++) {
            currentSamples[i][j] = 0;
        }
    }
}
