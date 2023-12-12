#ifndef WAV_WRITER_H
#define WAV_WRITER_H

#include "wav.h"
#include <iostream>
#include <fstream>
#include <exception>

namespace writer {
    class Writer {
    public:
        Writer(const std::string path);

        ~Writer() {};

        void writeSample(const wav::SampleBuffer *buffer);

        void writeHeader();

    private:
        wav::Header wav;
        std::ofstream outputFile;
    };
}
#endif
