#include "mix.h"

#include <memory>

using namespace mix;

Mix::Mix() { eh = ErrorHandler("mix"); }

bool Mix::convert(wav::SampleBuffer *currentSamples,
                  wav::SampleBuffer &originalSamples, int sec) {
    if (currentSamples == nullptr) {
        throw std::invalid_argument("invalid sample.");
    }
    if (isWorkTime(sec)) {
        for (int j = 0; j < wav::SAMPLES_PER_SEC; j++) {
            (*currentSamples)[j] =
                ((*currentSamples)[j] / 2 + originalSamples[j] / 2);
        }
    }
    return true;
}

bool Mix::isWorkTime(int sec) const { return (sec >= start); }

void Mix::initConverter(const std::vector<std::string> &params) {
    if (params.size() < 3) {
        throw std::runtime_error("invalid parameters count");
    }
    std::string strIndexFile = params[1];
    inputFile = std::stoi(strIndexFile.erase(0, 1)) - 1;
    start = std::stoi(params[2]);
}

int Mix::requiredFile() { return inputFile; }
