#ifndef SOUNDPROCESSOR_MUTE_H
#define SOUNDPROCESSOR_MUTE_H


#include "converter.h"

namespace mute {

    class Mute : public converter::Converter {
    public:
        Mute(const std::vector<std::string> &parameters);

        wav::SampleBuffer *convert(
                wav::SampleBuffer &current_samples,
                wav::SampleBuffer &original_samples,
                int sec
        ) override;

    private:
        int start = 0;
        int end = 0;
    };
}
#endif
