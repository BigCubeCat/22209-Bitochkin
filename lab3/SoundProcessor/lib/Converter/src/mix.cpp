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

wav::SampleBuffer *Mix::convert(
        wav::SampleBuffer &current_samples,
        wav::SampleBuffer &original_samples,
        int sec
) {
    auto *buf = new wav::SampleBuffer();
    for (int j = 0; j < wav::SAMPLES_PER_SEC; j++) {
        buf[sec][j] = ((&current_samples)[sec][j] / 2 + (&original_samples)[sec][j] / 2);
    }
    return buf;
}