#ifndef SOUNDPROCESSOR_CONVERTER_H
#define SOUNDPROCESSOR_CONVERTER_H

#include <vector>
#include <array>
#include <stdexcept>
#include "wav.h"
#include "../../ErrorHandler/ErrorHandler.h"

namespace converter {
    class Converter {
    public:
        virtual ~Converter() { delete eh; };

        virtual void convert(std::vector<wav::SampleBuffer> &current_samples,
                             const std::vector<wav::SampleVector> original_samples) = 0;

        ErrorHandler *eh = nullptr;
    };
}
#endif
