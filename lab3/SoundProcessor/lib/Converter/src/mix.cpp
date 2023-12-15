#include <memory>
#include "mix.h"

using namespace mix;

Mix::Mix(const std::vector<std::string> parameters) {
    if (parameters.size() < 3) {
        throw std::runtime_error("invalid parameters count");
    }
    std::string strIndexFile = parameters[1];
    this->indexFile = std::stoi(strIndexFile.erase(0, 1)) - 1;
    this->start = std::stoi(parameters[2]);
    this->eh = ErrorHandler("mix");
}

bool Mix::convert(
        wav::SampleBuffer *currentSamples,
        wav::SampleBuffer *originalSamples,
        int sec
) {
    for (int j = 0; j < wav::SAMPLES_PER_SEC; j++) {
        (*currentSamples)[j] = ((*currentSamples)[j] / 2 + (*originalSamples)[j] / 2);
    }
    return true;
}