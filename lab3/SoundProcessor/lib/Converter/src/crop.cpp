#include "crop.h"

using namespace crop;

Crop::Crop(const std::vector<std::string> &parameters) {
    begin = std::stoi(parameters[1]);
    end = std::stoi(parameters[2]);
}

void Crop::convert(
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

    currentSamples.erase(std::next(currentSamples.begin() + end));
    currentSamples.erase(
            std::next(currentSamples.begin()),
            std::next(currentSamples.begin() + begin - 1)
    );
}
