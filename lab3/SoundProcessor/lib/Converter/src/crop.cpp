#include "crop.h"

using namespace crop;

Crop::Crop(const std::vector<std::string> &parameters) {
    if (parameters.size() < 2) {
        throw std::runtime_error("invalid parameters count");
    }
    begin = std::stoi(parameters[1]);
    end = std::stoi(parameters[2]);
    eh = ErrorHandler("crop");
}

wav::SampleBuffer *Crop::convert(wav::SampleBuffer &currentSamples, wav::SampleBuffer &originalSamples, int sec) {
    if (sec >= begin && sec <= end) {
        return &currentSamples;
    }
    return nullptr;
}
