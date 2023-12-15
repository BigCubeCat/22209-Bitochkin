#ifndef SOUNDPROCESSOR_MUTE_H
#define SOUNDPROCESSOR_MUTE_H


#include "converter.h"

namespace mute {

    class Mute : public converter::Converter {
    public:
        Mute(const std::vector<std::string> &parameters);

        bool convert(
                wav::SampleBuffer *current_samples,
                wav::SampleBuffer &original_samples,
                int sec
        ) override;

        int requiredFile() override;

    private:
        int inputFile = 0;
        int start = 0;
        int end = 0;
    };
}
#endif
