#ifndef WAV_WAV_H
#define WAV_WAV_H

#include <cstdint>
#include <vector>
#include <array>
#include <string>

namespace wav {
    const uint32_t RIFF_CHUNK_ID = 0x46464952;
    const uint32_t WAVE_FORMAT = 0x45564157;

    const uint32_t FMT_CHUNK_ID = 0x20746d66;
    const uint16_t FMT_CHUNK_SIZE = 16; // FOR PCM
    const uint16_t AUDIO_FORMAT = 0x0001;
    const uint16_t NUMBER_CHANNELS = 1;
    const uint32_t SAMPLES_PER_SEC = 44100;

    const uint16_t BYTE_SIZE = 8;
    const uint16_t BITS_PER_SAMPLE = BYTE_SIZE * sizeof(int16_t);
    const uint16_t BLOCK_ALIGN = BITS_PER_SAMPLE * NUMBER_CHANNELS / BYTE_SIZE;
    const uint32_t BYTES_PER_SEC = BLOCK_ALIGN * SAMPLES_PER_SEC;

    const uint32_t DATA_CHUNK_ID = 0x61746164;
    const uint16_t TOTAL_HEADER_SIZE = 44;

    using SampleBuffer = std::array<int16_t, SAMPLES_PER_SEC>;
    using SampleVector = std::vector<SampleBuffer>;

    struct Header {
        uint32_t ChunkId;
        uint32_t ChunkSize;
    };

    struct WAV {
        /* RIFF Chunk  */
        Header RIFFHeader;
        uint32_t WAVEFormat;

        /* fmt sub-chunk */
        Header FMTHeader;

        uint16_t audioFormat;
        uint16_t numberChannels;
        uint32_t samplesPerSec;
        uint32_t bytesPerSec;
        uint16_t blockAlign;
        uint16_t bitsPerSample;

        /* data sub-chunk */
        Header dataHeader;
    };
}
#endif
