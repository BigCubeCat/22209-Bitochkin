#ifndef SOUNDPROCESSOR_CROP_H
#define SOUNDPROCESSOR_CROP_H

#include "converter.h"

namespace crop {
    class Crop : public converter::Converter {
    public:
        explicit Crop(const std::vector<std::string> &parameters);

        void convert(std::vector<wav::SampleBuffer> &current_samples,
                     const std::vector<wav::SampleVector> original_samples) override;

    private:
        int begin = 0;
        int end = 0;
    };
}
#endif
