#ifndef SOUNDPROCESSOR_MIX_H
#define SOUNDPROCESSOR_MIX_H

#include "converter.h"

namespace mix {
    class Mix : public converter::Converter {
    public:
        explicit Mix(const std::vector<std::string> &parameters);

        void convert(
                std::vector<wav::SampleBuffer> &currentSamples,
                const std::vector<wav::SampleVector> &originalSamples
        ) override;

    private:
        int begin = 0;
        int indexFile;
    };
}

#endif
