#include "mute.h"

using namespace mute;

Mute::Mute(const std::vector<std::string> parameters) {
    start = std::stoi(parameters[1]);
    end = std::stoi(parameters[2]);
}

void Mute::convert(std::vector<wav::SampleBuffer> &current_samples,
                   const std::vector<wav::SampleVector> original_samples) {
    if (start >= current_samples.size()) throw converter::WrongTime(start);
    if (end >= current_samples.size()) throw converter::WrongTime(end);


    for (int i = start; i <= end; i++) {
        for (int j = 0; j < wav::SAMPLES_PER_SEC; j++) {
            current_samples[i][j] -= (int16_t) (current_samples[i][j] * PERCENT);
        }
    }
}
