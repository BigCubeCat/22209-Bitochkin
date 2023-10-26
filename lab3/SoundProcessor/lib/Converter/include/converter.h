#ifndef SOUNDPROCESSOR_CONVERTER_H
#define SOUNDPROCESSOR_CONVERTER_H

#include "../../WAV/include/wav.h"

namespace converter {
    class Converter {
    public:
        virtual ~Converter() = default;

        virtual void convert(
                std::vector<wav::SampleBuffer> &currentSamples,
                const std::vector<wav::SampleVector> &originalSamples
        ) = 0;

        bool errorsOccurred = false;
        std::string errorMessage;
    };
}
#endif
