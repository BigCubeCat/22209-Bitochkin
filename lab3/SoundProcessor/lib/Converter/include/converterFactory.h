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

    class NotFoundConverter : public std::invalid_argument {
    public:
        explicit NotFoundConverter(const std::string &converterName);
    };

    const std::string MUTE = "mute";
    const std::string MIX = "mix";
    const std::string NOISE = "noise";
    const std::string CUT = "cut";
    const std::string CROP = "crop";


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
