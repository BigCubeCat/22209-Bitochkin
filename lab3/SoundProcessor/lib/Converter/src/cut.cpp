#include "cut.h"

#include <iostream>

using namespace cut;

Cut::Cut(const std::vector<std::string> &parameters) {
    begin = std::stoi(parameters[1]);
    end = std::stoi(parameters[2]);
    this->eh = new ErrorHandler("cut");
}

void Cut::convert(std::vector<wav::SampleBuffer> &currentSamples,
                  const std::vector<wav::SampleVector> originalSamples) {
    std::cout << "\nbegin, end " << begin << " " << end << "\t" << currentSamples.size() << "\n";

    if (begin >= currentSamples.size()) {
        eh->AddError("invalid begin time\n");
        return;
    }
    if (end >= currentSamples.size()) {
        eh->AddError("invalid end time\n");
        return;
    }

    currentSamples.erase(
            std::next(currentSamples.begin() + begin),
            std::next(currentSamples.begin() + end - 1)
    );
}