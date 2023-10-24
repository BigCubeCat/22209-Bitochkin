#include "converterFactory.h"
using namespace converterFactory;

NotFoundConverter ::NotFoundConverter(const std::string &converterName)
                                            : std::invalid_argument (converterName + " not found"){}

ConverterPointer ConverterFactory::createConverter(const std::vector<std::string> parameters)
{
    std::string converterName = parameters[0];

    if (converterName == MIX)               return std::make_unique<mix::Mix>(parameters);
    else if (converterName == MUTE)         return std::make_unique<mute::Mute>(parameters);
    else if (converterName == NOISE)        return std::make_unique<noise::Noise>(parameters);
    else                                    throw NotFoundConverter(converterName);
}


