#ifndef SOUNDPROCESSOR_MIX_H
#define SOUNDPROCESSOR_MIX_H

#include "converter.h"
#include <stdexcept>

namespace mix {

    class WrongFileIndex: public std::invalid_argument{
    public:
        WrongFileIndex(const int index);
    };

    class Mix : public converter::Converter {
    public:
        Mix(const std::vector<std::string> parameters);

        void convert(std::vector<wav::SampleBuffer> &current_samples,
                     const std::vector<wav::SampleVector> original_samples) override;

    private:
        int start = 0;
        int indexFile;
    };
}

#endif
