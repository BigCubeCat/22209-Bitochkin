#ifndef SOUNDPROCESSOR_STEPALGO_H
#define SOUNDPROCESSOR_STEPALGO_H

#include <vector>

struct StepAlgo {
    std::vector<int> usedConverters; // Индексы исполльзуемых конвертеров
    std::vector<int> usedFile; // индекс используемого файла
    int sec;
};

#endif
