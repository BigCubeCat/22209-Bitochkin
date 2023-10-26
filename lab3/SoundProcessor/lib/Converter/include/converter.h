#ifndef SOUNDPROCESSOR_CONVERTER_H
#define SOUNDPROCESSOR_CONVERTER_H

#include "../../WAV/include/wav.h"

namespace converter {
    class WrongTime : public std::invalid_argument {
    public:
        explicit WrongTime(const int time) : std::invalid_argument(std::to_string(time) + " is wrong time format") {};
    };

    class Converter {
    public:
        virtual ~Converter() = default;

        virtual void convert(
                std::vector<wav::SampleBuffer> &currentSamples,
                const std::vector<wav::SampleVector> &originalSamples
        ) = 0;
    };
}
#endif
