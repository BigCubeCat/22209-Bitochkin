#ifndef SOUNDPROCESSOR_MUTE_H
#define SOUNDPROCESSOR_MUTE_H

#include "converter.h"

namespace mute {

class Mute : public converter::Converter {
   public:
    Mute();

    bool convert(wav::SampleBuffer &current_samples,
                const wav::SampleBuffer &original_samples, int sec) override;

    int requiredFile() override;

    void initConverter(const std::vector<std::string> &params) override;

    bool isWorkTime(int sec) const override;

   private:
    int inputFile = 0;
    int start = 0;
    int end = 0;
};
}  // namespace mute
#endif
