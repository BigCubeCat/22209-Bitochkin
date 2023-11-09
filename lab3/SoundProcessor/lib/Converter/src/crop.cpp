#include "crop.h"

using namespace crop;

Crop::Crop(const std::vector<std::string> &parameters) {
    begin = std::stoi(parameters[1]);
    end = std::stoi(parameters[2]);
    this->eh = new ErrorHandler("crop");
}

void Crop::convert(wav::SampleVector &current_samples,
                   const std::vector<wav::SampleVector> original_samples) {
    if (begin >= current_samples.size()) {
        eh->AddError("invalid begin size\n");
        return;
    }
    if (end >= current_samples.size()) {
        eh->AddError("invalid end size\n");
        return;
    }

    current_samples.erase(std::next(current_samples.begin() + end));
    current_samples.erase(
            std::next(current_samples.begin()),
            std::next(current_samples.begin() + begin - 1)
    );
}
