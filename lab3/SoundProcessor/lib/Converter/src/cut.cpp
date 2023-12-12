#include "cut.h"

#include <iostream>

using namespace cut;

Cut::Cut(const std::vector<std::string> &parameters) {
    if (parameters.size() < 2) {
        throw std::runtime_error("invalid parameters count");
    }
    begin = std::stoi(parameters[0]);
    end = std::stoi(parameters[1]);
    eh = ErrorHandler("cut");
}

void Cut::convert(std::vector<wav::SampleBuffer> &currentSamples,
                  const std::vector<wav::SampleVector> originalSamples) {
    std::cout << "\nbegin, end " << begin << " " << end << "\t" << currentSamples.size() << "\n";

    if (begin >= currentSamples.size()) {
        eh.AddError("invalid begin time\n");
        return;
    }
    if (end >= currentSamples.size()) {
        eh.AddError("invalid end time\n");
        return;
    }

    currentSamples.erase(
            std::next(currentSamples.begin() + begin),
            std::next(currentSamples.begin() + end - 1)
    );
}