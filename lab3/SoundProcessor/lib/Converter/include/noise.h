#ifndef SOUNDPROCESSOR_NOISE_H
#define SOUNDPROCESSOR_NOISE_H


#include "converter.h"

namespace noise {

    class Noise : public converter::Converter {
    public:
        Noise(const std::vector<std::string> &parameters);

        void convert(
                wav::SampleBuffer *current_samples,
                wav::SampleBuffer *original_samples,
                int sec
        ) override;

    private:
        int start = 0;
        int end = 0;
        int percent = 50;
    };
}
#endif
