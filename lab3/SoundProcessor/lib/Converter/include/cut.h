#ifndef SOUNDPROCESSOR_CUT_H
#define SOUNDPROCESSOR_CUT_H

#include "converter.h"

namespace cut {
    class Cut : public converter::Converter {
    public:
        explicit Cut(const std::vector<std::string> &parameters);

        bool convert(
                wav::SampleBuffer *currentSamples,
                wav::SampleBuffer *originalSamples,
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
