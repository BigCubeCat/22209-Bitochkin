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
    std::cout << "processor run\n";
    int sampleSize = 0;

    converterFactory::ConverterFactory factory;

    writer::Writer writer(outFile);
    reader::Reader reader;
    reader.load(inputFiles[0]); // Загружаем input file
    wav::SampleVector currentSample;

    wav::SampleBuffer buffer;
    while (reader.readSample(&buffer)) {
        for (const auto &instruction: algorithm) {
            std::cout << "instruction: " << instruction.name << "\n";
            // converterFactory::ConverterPointer currentConverter = factory.createConverter(instruction.args);
            // currentConverter->convert(&buffer, &buffer, sampleSize);
        }
        writer.writeSample(&buffer);
    }
    writer.writeHeader();
}
