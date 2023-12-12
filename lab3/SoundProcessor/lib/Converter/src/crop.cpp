#include "crop.h"

using namespace crop;

Crop::Crop(const std::vector<std::string> &parameters) {
    if (parameters.size() < 2) {
        throw std::runtime_error("invalid parameters count");
    }
    begin = std::stoi(parameters[0]);
    end = std::stoi(parameters[1]);
    eh = ErrorHandler("crop");
}

void Crop::convert(std::vector<wav::SampleBuffer> &currentSamples,
                   const std::vector<wav::SampleVector> originalSamples) {
    if (begin >= currentSamples.size()) {
        eh.AddError("invalid begin size\n");
        return;
    }
    if (end >= currentSamples.size()) {
        eh.AddError("invalid end size\n");
        return;
    }

    currentSamples.erase(
            std::next(currentSamples.begin() + end),
            std::next(currentSamples.end()
            )
    );
    currentSamples.erase(
            std::next(currentSamples.begin()),
            std::next(currentSamples.begin() + begin - 1)
    );
}