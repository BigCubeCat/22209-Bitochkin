#ifndef SOUNDPROCESSOR_MIX_H
#define SOUNDPROCESSOR_MIX_H


#include "converter.h"
#include <stdexcept>

namespace mix {
    class Mix : public converter::Converter {
    public:
        Mix(const std::vector<std::string> parameters);

        void convert(
                wav::SampleBuffer *current_samples,
                wav::SampleBuffer *original_samples,
                int sec
        ) override;

    private:
        int start = 0;
        int indexFile;
    };
}

#endif
