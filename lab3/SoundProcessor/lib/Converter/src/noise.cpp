#include "noise.h"

using namespace noise;

Noise::Noise(const std::vector<std::string> &parameters) {
    start = std::stoi(parameters[0]);
    end = std::stoi(parameters[1]);
    percent = std::stoi(parameters[2]);
    this->eh = new ErrorHandler("noise");
}

void Noise::convert(std::vector<wav::SampleBuffer> &current_samples,
                    const std::vector<wav::SampleVector> original_samples) {
    if (start >= current_samples.size()) {
        eh->AddError("wrong start format");
        return;
    }
    if (end >= current_samples.size()) {
        eh->AddError("wrong end format");
        return;
    }

    if (percent < 0 || percent > 100) {
        eh->AddError("wrong percent (not in range 0-100");
        return;
    }

    for (int i = start; i <= end; i++) {
        for (int j = 0; j < wav::SAMPLES_PER_SEC; j++) {
            current_samples[i][j] -= (int16_t) (current_samples[i][j] * percent);
        }
    }
}
