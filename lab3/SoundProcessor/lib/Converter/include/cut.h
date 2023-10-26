#ifndef SOUNDPROCESSOR_CUT_H
#define SOUNDPROCESSOR_CUT_H

#include "converter.h"

namespace cut {
    class Cut : public converter::Converter {
    public:
        explicit Cut(const std::vector<std::string>& parameters);

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
