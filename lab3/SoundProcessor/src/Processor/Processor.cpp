#include "Processor.h"
#include "reader.h"
#include "writer.h"
#include "converterFactory.h"
#include <stdexcept>

Processor::Processor(
        const std::vector<std::string> &input,
        const std::string &output
) : inputFiles(input), outFile(output) {
    initSamples();
}

void Processor::initSamples() {

}

void Processor::run(const std::vector<ConverterConfig> &algorithm) {
    int sampleSize = 0;

    converterFactory::ConverterFactory factory;

    writer::Writer writer(outFile);
    reader::Reader reader;
    reader.load(inputFiles[0]); // Загружаем input file
    wav::SampleVector currentSample;

    std::vector<converterFactory::ConverterPointer> algo(algorithm.size());
    for (int i = 0; i < algorithm.size(); ++i) {
        algo[i] = factory.createConverter(algorithm[i].args);
    }

    wav::SampleBuffer buffer;
    bool useNewSample = true;
    while (reader.readSample(&buffer)) {
        for (const auto & converter : algo) {
             useNewSample = useNewSample && converter->convert(&buffer, &buffer, sampleSize);
        }
        if (useNewSample) {
            writer.writeSample(&buffer);
        }
        ++sampleSize;
    }
    writer.writeHeader();
}
