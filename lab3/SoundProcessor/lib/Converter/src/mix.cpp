#include <stdexcept>
#include "mix.h"

using namespace mix;

WrongFileIndex::WrongFileIndex(const int index) : std::invalid_argument(std::to_string(index) + "is bad argument") {}

Mix::Mix(const std::vector<std::string> &parameters) {
    std::string strIndexFile = parameters[1];
    this->indexFile = std::stoi(strIndexFile.erase(0, 1)) - 1;
    this->start = std::stoi(parameters[2]);
}

void Mix::convert(
        wav::SampleVector &currentSamples,
        const std::vector<wav::SampleVector> &originalSamples
) {
    if (indexFile < 0 || indexFile >= originalSamples.size()) {
        throw WrongFileIndex(indexFile);
    }

    if (start >= currentSamples.size()) throw converter::WrongTime(start);

    for (int i = start; i < currentSamples.size() && i < originalSamples[indexFile].size(); i++) {
        for (int j = 0; j < wav::SAMPLES_PER_SEC; j++) {
            currentSamples[i][j] = (
                    currentSamples[i][j] / 2 + originalSamples[indexFile][i][j] / 2
            );
        }
    }
}