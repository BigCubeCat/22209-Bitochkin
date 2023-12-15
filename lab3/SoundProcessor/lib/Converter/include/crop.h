#ifndef SOUNDPROCESSOR_CROP_H
#define SOUNDPROCESSOR_CROP_H

#include "converter.h"

namespace crop {
    class Crop : public converter::Converter {
    public:
        explicit Crop(const std::vector<std::string> &parameters);

        bool convert(
                wav::SampleBuffer *current_samples,
                wav::SampleBuffer *original_samples,
                int sec = 0
        ) override;
        int requiredFile() override;

    private:
        int inputFile = 0;
        int begin = 0;
        int end = 0;
    };
}
#endif
