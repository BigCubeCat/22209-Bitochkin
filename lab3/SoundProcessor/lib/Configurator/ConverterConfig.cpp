#include "ConverterConfig.h"

ConverterConfig::ConverterConfig(std::vector<std::string> params) {
    if (params.empty()) {
        return;
    }
    name = params[0];
    for (int i = 1; i < params.size(); ++i) {
        args.push_back(params[i]);
    }
}
