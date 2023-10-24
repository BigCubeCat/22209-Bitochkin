#ifndef SOUNDPROCESSOR_MUTE_H
#define SOUNDPROCESSOR_MUTE_H

#include "converter.h"

namespace mute {
    const float PERCENT = 0.9f;

    class Mute : public converter::Converter {
    public:
        Mute(const std::vector<std::string> parameters);

        void convert(std::vector<wav::SampleBuffer> &current_samples,
                     const std::vector<wav::SampleVector> original_samples) override;

    private:
        int start = 0;
        int end = 0;
    };
}
#endif
