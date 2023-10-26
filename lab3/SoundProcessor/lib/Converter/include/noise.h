#ifndef SOUNDPROCESSOR_NOISE_H
#define SOUNDPROCESSOR_NOISE_H

#include "converter.h"

namespace noise {
    class Noise : public converter::Converter {
    public:
        explicit Noise(const std::vector<std::string> &parameters);

        void convert(
                std::vector<wav::SampleBuffer> &currentSamples,
                const std::vector<wav::SampleVector> &originalSamples
        ) override;

    private:
        int start = 0;
        int end = 0;
        int percent = 0;
    };
}
#endif
