#ifndef SOUNDPROCESSOR_MIX_H
#define SOUNDPROCESSOR_MIX_H


#include "converter.h"
#include <stdexcept>

namespace mix {
    class Mix : public converter::Converter {
    public:
        Mix();

        bool convert(
                wav::SampleBuffer *current_samples,
                wav::SampleBuffer &original_samples,
                int sec
        ) override;

        int requiredFile() override;

        void initConverter(const std::vector<std::string> &params) override;

        bool isWorkTime(int sec) const override;

    private:
        int inputFile = 0;
        int start = 0;

    };
}

#endif
