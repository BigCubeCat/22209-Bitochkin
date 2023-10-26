#include <stdexcept>
#include "mix.h"

using namespace mix;

Mix::Mix(const std::vector<std::string> &parameters) {
    std::string strIndexFile = parameters[1];
    this->indexFile = std::stoi(strIndexFile.erase(0, 1)) - 1;
    this->begin = std::stoi(parameters[2]);
}

void Mix::convert(
        wav::SampleVector &currentSamples,
        const std::vector<wav::SampleVector> &originalSamples
) {
    if (indexFile < 0 || indexFile >= originalSamples.size()) {
        errorsOccurred = true;
        errorMessage += "Invalid file index\n";
    }

    if (begin >= currentSamples.size()) {
        errorsOccurred = true;
        errorMessage += "Invalid begin time\n";
    }

    if (errorsOccurred) return;

    for (int i = begin; i < currentSamples.size() && i < originalSamples[indexFile].size(); i++) {
        for (int j = 0; j < wav::SAMPLES_PER_SEC; j++) {
            currentSamples[i][j] = (
                    currentSamples[i][j] / 2 + originalSamples[indexFile][i][j] / 2
            );
        }
    }
}