#include "noise.h"

using namespace noise;

Noise::Noise(const std::vector<std::string> &parameters) {
    if (parameters.size() < 3) {
        throw std::runtime_error("invalid parameters count");
    }
    start = std::stoi(parameters[1]);
    end = std::stoi(parameters[2]);
    percent = std::stoi(parameters[3]);
    eh = ErrorHandler("noise");
    if (percent < 0 || percent > 100) {
        eh.AddError("wrong percent (not in range 0-100");
    }
}

wav::SampleBuffer *Noise::convert(
        wav::SampleBuffer &current_samples,
        wav::SampleBuffer &original_samples,
        int sec
) {
    auto *buf = new wav::SampleBuffer();
    if (sec >= start && sec <= end) {
        for (int j = 0; j < wav::SAMPLES_PER_SEC; j++) {
            buf[sec][j] -= (int16_t) ((&current_samples)[sec][j] * percent);
        }
    }
    return buf;
}
