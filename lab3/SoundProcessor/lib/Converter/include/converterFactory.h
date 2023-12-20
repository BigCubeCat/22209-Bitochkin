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

    std::map<std::string, std::function<ConverterPointer ()>> converterMap = {
            {"mix", []() {return std::make_unique<mix::Mix>();}},
            {"mute", []() {return std::make_unique<mute::Mute>();}},
            {"crop", []() {return std::make_unique<crop::Crop>();}},
            {"cut", []() {return std::make_unique<cut::Cut>();}},
            {"noise", []() {return std::make_unique<noise::Noise>();}}
    };

    class ConverterFactory {
    public:
        static ConverterPointer createConverter(const std::string& name) {
            return converterMap[name]();
        };
    };
}
#endif
