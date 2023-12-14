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
    std::cout << "create writer\n";
    reader::Reader reader;
    std::cout << "create reader\n";
    std::cout << inputFiles[0] << '\n';
    reader.load(inputFiles[0]); // Загружаем input file
    std::cout << "loaded\n";
    wav::SampleVector currentSample;

    while (true) {
        wav::SampleBuffer buffer;
        if (!reader.readSample(&buffer)) break;
        for (const auto &instruction: algorithm) {
            std::cout << "instruction: " << instruction.name << "\n";
            converterFactory::ConverterPointer currentConverter = factory.createConverter(instruction.args);
            currentConverter->convert(&buffer, &buffer, sampleSize);
        }
        writer.writeSample(&buffer);
        sampleSize++;
    }

    writer.writeHeader();
}
