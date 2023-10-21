#ifndef WAV_WRITER_H
#define WAV_WRITER_H

#include "wav.h"
#include <fstream>

namespace writer {
    class Writer {
    public:
        Writer(const std::string path);

        ~Writer() {};

        void writeSample(const wav::SampleBuffer *buffer);

        void writeHeader();

    private:
        wav::WAV wav;
        std::ofstream outputFile;
    };
}
#endif
