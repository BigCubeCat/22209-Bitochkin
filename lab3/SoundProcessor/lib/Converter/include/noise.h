#ifndef SOUNDPROCESSOR_NOISE_H
#define SOUNDPROCESSOR_NOISE_H

#include "converter.h"

namespace noise {

class Noise : public converter::Converter {
   public:
    Noise();

    bool convert(wav::SampleBuffer *currentSamples,
                 wav::SampleBuffer &originalSamples, int sec) override;

    int requiredFile() override;

    void initConverter(const std::vector<std::string> &params) override;

    bool isWorkTime(int sec) const override;

   private:
    int inputFile = 0;
    int start = 0;
    int end = 0;
    int percent = 50;
};
}  // namespace noise
#endif
