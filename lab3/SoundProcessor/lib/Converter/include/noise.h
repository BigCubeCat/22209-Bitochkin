#ifndef SOUNDPROCESSOR_NOISE_H
#define SOUNDPROCESSOR_NOISE_H


#include "converter.h"

namespace noise {

    const float PERCENT = 50.5f;

    class Noise : public converter::Converter {
    public:
        Noise(const std::vector<std::string> parameters);

        void convert(std::vector<wav::SampleBuffer> &current_samples,
                     const std::vector<wav::SampleVector> original_samples) override;

    private:
        int start = 0;
        int end = 0;
    };
}
#endif
