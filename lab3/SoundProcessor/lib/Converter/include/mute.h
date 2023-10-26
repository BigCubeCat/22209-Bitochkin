#ifndef SOUNDPROCESSOR_MUTE_H
#define SOUNDPROCESSOR_MUTE_H

#include "converter.h"

namespace mute {
    class Mute : public converter::Converter {
    public:
        explicit Mute(const std::vector<std::string>& parameters);

        void convert(
                std::vector<wav::SampleBuffer> &currentSamples,
                const std::vector<wav::SampleVector> &originalSamples
        ) override;

    private:
        int begin = 0;
        int end = 0;
    };
}
#endif
