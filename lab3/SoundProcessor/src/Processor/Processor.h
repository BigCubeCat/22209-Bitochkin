#ifndef SOUNDPROCESSOR_PROCESSOR_H
#define SOUNDPROCESSOR_PROCESSOR_H

#include <vector>
#include <string>
#include "wav.h"
#include "../../lib/Configurator/ConverterConfig.h"

class Processor {
public:
    Processor(
            const std::vector<std::string> &input,
            const std::string &output
    );

    void run(const std::vector<ConverterConfig> & algorithm);

    void writeOut(const std::vector<wav::SampleBuffer> &resultSamples);

private:
    void initSamples();

    std::vector<std::string> inputFiles;
    std::string outFile;

    std::vector<wav::SampleVector> inputFilesSamples;
};


#endif
