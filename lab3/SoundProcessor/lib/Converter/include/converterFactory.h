#ifndef SOUNDPROCESSOR_CONVERTERFACTORY_H
#define SOUNDPROCESSOR_CONVERTERFACTORY_H

#include <memory>
#include "mute.h"
#include "mix.h"
#include "noise.h"

namespace converterFactory {

    class NotFoundConverter : public std::invalid_argument {
    public:
        explicit NotFoundConverter(const std::string &converterName);
    };

    const std::string MUTE = "mute";
    const std::string MIX = "mix";
    const std::string NOISE = "noise";

    using ConverterPointer = std::unique_ptr<converter::Converter>;

    class ConverterFactory {
    public:
        ConverterPointer createConverter(const std::vector<std::string> &parameters);
    };
}
#endif
