#include <memory>
#include "mix.h"

using namespace mix;

Mix::Mix(const std::vector<std::string> parameters) {
    std::string strIndexFile = parameters[1];
    this->indexFile = std::stoi(strIndexFile.erase(0, 1)) - 1;
    this->start = std::stoi(parameters[2]);
    this->eh = new ErrorHandler("mix");
}

void Mix::convert(wav::SampleVector &current_samples,
                  const std::vector<wav::SampleVector> original_samples) {
    if (indexFile < 0 || indexFile >= original_samples.size()) {
        eh->AddError(std::to_string(indexFile) + " is bad argument\n");
        return;
    }
    if (start >= current_samples.size()) {
        eh->AddError(std::to_string(start) + " bad time format\n");
        return;
    }

    for (int i = start; i < current_samples.size() && i < original_samples[indexFile].size(); i++) {
        for (int j = 0; j < wav::SAMPLES_PER_SEC; j++) {
            current_samples[i][j] = (current_samples[i][j] / 2 + original_samples[indexFile][i][j] / 2);
        }
    }
}