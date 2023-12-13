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
        // Тут специально указатель, чтобы для crop и cut выводить nullptr
        virtual wav::SampleBuffer *convert(
                wav::SampleBuffer &current_samples,
                wav::SampleBuffer &original_samples,
                int sec = 0
        ) = 0;

        ErrorHandler eh = ErrorHandler("default");
    };
}
#endif
