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
    for (const auto &inputFile: inputFiles) {
        reader::Reader reader;
        reader.load(inputFile);

        wav::SampleVector currentSample;

        while (true) {
            wav::SampleBuffer buffer;
            if (!reader.readSample(&buffer)) break;
            currentSample.push_back(buffer);
        }
        inputFilesSamples.push_back(currentSample);
    }
}

void Processor::run(const std::vector<ConverterConfig> &algorithm) {
    wav::SampleVector resultSamples = inputFilesSamples[0];

    converterFactory::ConverterFactory factory;

    for (const auto &instruction: algorithm) {
        std::cout << "\ncmd\t" << instruction.name << "\n";
        converterFactory::ConverterPointer currentConverter = factory.createConverter(instruction.args);
        currentConverter->convert(resultSamples, inputFilesSamples);
        if (currentConverter->eh->hasErrors()) {
            currentConverter->eh->printErrorText();
            return;
        }
    }

    writeOut(resultSamples);
}

void Processor::writeOut(const std::vector<wav::SampleBuffer> &resultSamples) {
    writer::Writer writer(outFile);
    for (const auto &buffer: resultSamples) {
        writer.writeSample(&buffer);
    }
    writer.writeHeader();
}
