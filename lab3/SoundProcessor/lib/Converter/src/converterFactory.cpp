#include "converterFactory.h"

using namespace converterFactory;

ConverterPointer ConverterFactory::createConverter(const std::vector<std::string> parameters) {
    const std::string& converterName = parameters[0];
    if (converterName == MIX) {
        return std::make_unique<mix::Mix>(parameters);
    } else if (converterName == MUTE) {
        return std::make_unique<mute::Mute>(parameters);
    } else if (converterName == NOISE) {
        return std::make_unique<noise::Noise>(parameters);
    } else if (converterName == CUT) {
        return std::make_unique<cut::Cut>(parameters);
    } else {
        return std::make_unique<crop::Crop>(parameters);
    }
}
