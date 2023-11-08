#include "cut.h"

using namespace cut;

Cut::Cut(const std::vector<std::string> &parameters) {
    begin = std::stoi(parameters[1]);
    end = std::stoi(parameters[2]);
}

void Cut::convert(
        std::vector<wav::SampleBuffer> &currentSamples,
        const std::vector<wav::SampleVector> &originalSamples
) {
    if (begin >= currentSamples.size()) {
    }
    if (end >= currentSamples.size()) {


    if (errorsOccurred) return;

    currentSamples.erase(
            std::next(currentSamples.begin() + begin),
            std::next(currentSamples.begin() + end - 1)
    );
}
