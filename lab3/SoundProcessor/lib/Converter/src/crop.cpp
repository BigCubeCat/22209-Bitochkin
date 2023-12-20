#include "crop.h"

using namespace crop;

Crop::Crop() { eh = ErrorHandler("crop"); }

void Crop::initConverter(const std::vector<std::string> &params) {
    if (params.size() < 2) {
        throw std::runtime_error("invalid parameters count");
    }
    begin = std::stoi(params[1]);
    end = std::stoi(params[2]);
}

bool Crop::convert(wav::SampleBuffer *currentSamples,
                   wav::SampleBuffer &originalSamples, int sec) {
    if (currentSamples == nullptr) {
        throw std::invalid_argument("invalid sample.");
    }
    return isWorkTime(sec);
}

bool Crop::isWorkTime(int sec) const { return (sec >= begin && sec <= end); }

int Crop::requiredFile() { return inputFile; }
