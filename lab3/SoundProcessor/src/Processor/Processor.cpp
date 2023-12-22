#include "Processor.h"

#include <stdexcept>

#include "converterFactory.h"
#include "reader.h"
#include "writer.h"

Processor::Processor(const std::vector<std::string> &input,
                     const std::string &output)
    : inputFiles(input), outFile(output) {}

void Processor::run(const std::vector<ConverterConfig> &algorithm) {
    int sampleSize = 0;

    converterFactory::ConverterFactory factory;

    writer::Writer writer(outFile);
    reader::Reader reader;
    wav::SampleVector currentSample;

    std::vector<converterFactory::ConverterPointer> algo(algorithm.size());
    std::vector<int> requiredConverterFiles(algorithm.size());

    std::vector<bool> usedFiles(inputFiles.size());
    std::fill(usedFiles.begin(), usedFiles.end(), false);
    std::vector<reader::Reader> readers(inputFiles.size());

    for (int i = 0; i < algorithm.size(); ++i) {
        algo[i] = factory.createConverter(algorithm[i].name);
        algo[i]->initConverter(algorithm[i].args);
        requiredConverterFiles[i] = algo[i]->requiredFile();
        usedFiles[requiredConverterFiles[i]] = true;
    }
    usedFiles[0] = true;

    for (int i = 0; i < inputFiles.size(); ++i) {
        if (usedFiles[i]) {
            readers[i].loadHeader(inputFiles[i]);
        }
    }
    wav::SampleBuffer buffer;
    wav::SampleBuffer secondBuffer;
    bool useNewSample = true;
    while (readers[0].readSample(&buffer)) {
        for (int i = 0; i < algo.size(); ++i) {
            if (requiredConverterFiles[i] != 0 &&
                algo[i]->isWorkTime(sampleSize)) {
                // Если нужен какой-то другой файл, мы читаем его кусочек, иначе
                // берем кусочек старого
                if (!readers[requiredConverterFiles[i]].readSample(
                        &secondBuffer)) {
                    secondBuffer = buffer;
                }
            } else {
                secondBuffer = buffer;
            }
            useNewSample = useNewSample &&
                           algo[i]->convert(buffer, secondBuffer, sampleSize);
        }
        if (useNewSample) {
            writer.writeSample(&buffer);
        }
        ++sampleSize;
    }
    writer.writeHeader();
}
