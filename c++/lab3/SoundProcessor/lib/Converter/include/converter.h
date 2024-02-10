#ifndef SOUNDPROCESSOR_CONVERTER_H
#define SOUNDPROCESSOR_CONVERTER_H

#include <array>
#include <stdexcept>
#include <vector>

#include "../../ErrorHandler/ErrorHandler.h"
#include "wav.h"

namespace converter {
class Converter {
   public:
    virtual bool convert(wav::SampleBuffer &current_samples,
                         const wav::SampleBuffer &original_samples, int sec = 0) = 0;

    virtual int requiredFile() = 0;
    virtual bool isWorkTime(int sec) const = 0;

    virtual void initConverter(const std::vector<std::string> &params) = 0;

    ErrorHandler eh = ErrorHandler("default");

   private:
    int inputFile;
};
}  // namespace converter
#endif
