#ifndef SOUNDPROCESSOR_CUT_H
#define SOUNDPROCESSOR_CUT_H

#include "converter.h"

namespace cut {
    class Cut : public converter::Converter {
    public:
        explicit Cut(const std::vector<std::string> &parameters);

        wav::SampleBuffer *convert(
                wav::SampleBuffer &currentSamples,
                wav::SampleBuffer &originalSamples,
                int sec = 0
        ) override;

    private:
        int begin = 0;
        int end = 0;
    };
}
#endif
