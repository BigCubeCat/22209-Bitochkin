#ifndef SOUNDPROCESSOR_CONVERTERFACTORY_H
#define SOUNDPROCESSOR_CONVERTERFACTORY_H


#include <cstdlib>
#include <stdexcept>
#include <memory>
#include <string>
#include <map>
#include <functional>

#include "mute.h"
#include "mix.h"
#include "noise.h"
#include "cut.h"
#include "crop.h"

namespace converterFactory {
    using ConverterPointer = std::unique_ptr<converter::Converter>;

    std::map<std::string, std::function<ConverterPointer (const std::vector<std::string>&)>> converterMap = {
            {"mix", [](const std::vector<std::string> &params) {return std::make_unique<mix::Mix>(params);}},
            {"mute", [](const std::vector<std::string> &params) {return std::make_unique<mute::Mute>(params);}},
            {"crop", [](const std::vector<std::string> &params) {return std::make_unique<crop::Crop>(params);}},
            {"cut", [](const std::vector<std::string> &params) {return std::make_unique<cut::Cut>(params);}},
            {"noise", [](const std::vector<std::string> &params) {return std::make_unique<noise::Noise>(params);}}
    };

    class ConverterFactory {
    public:
        ConverterPointer createConverter(const std::vector<std::string> parameters) {
            return converterMap[parameters[0]](parameters);
        };
    };
}
#endif
