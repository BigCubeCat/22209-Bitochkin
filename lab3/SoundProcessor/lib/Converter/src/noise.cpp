#include "noise.h"

using namespace noise;

Noise::Noise() { eh = ErrorHandler("noise"); }

bool Noise::convert(wav::SampleBuffer *current_samples,
                    wav::SampleBuffer &original_samples, int sec) {
    if (sec >= start && sec < end) {
        for (int j = 0; j < wav::SAMPLES_PER_SEC; j++) {
            (*current_samples)[j] -=
                (int16_t)(current_samples[sec][j] * percent);
        }
    }
    return true;
}

bool Noise::isWorkTime(int sec) const { return (sec >= start && sec < end); }

void Noise::initConverter(const std::vector<std::string> &params) {
    if (params.size() < 3) {
        throw std::runtime_error("invalid parameters count");
    }
    start = std::stoi(params[1]);
    end = std::stoi(params[2]);
    percent = std::stoi(params[3]);
    if (percent < 0 || percent > 100) {
        eh.AddError("wrong percent (not in range 0-100");
    }
}

int Noise::requiredFile() { return inputFile; }
