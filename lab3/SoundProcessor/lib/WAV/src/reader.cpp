#include "reader.h"

using namespace reader;

WrongRIFFChunkId::WrongRIFFChunkId(const uint32_t RIFFChunkId) :
        std::invalid_argument(std::to_string(RIFFChunkId) + " is not RIFF") {}

WrongWAVEFormat::WrongWAVEFormat(const uint32_t wrongWAVEFormat) :
        std::invalid_argument(std::to_string(wrongWAVEFormat) + "is not WAVE") {}

WrongFMTChunkId::WrongFMTChunkId(const uint32_t FMTChunkId) :
        std::invalid_argument(std::to_string(FMTChunkId) + " is not FMT") {}

WrongAudioFormat::WrongAudioFormat(const uint16_t audioFormat) :
        std::invalid_argument(std::to_string(audioFormat) + " is not PML") {}

WrongNumberChannels::WrongNumberChannels(const uint16_t numberChannels) :
        std::invalid_argument(std::to_string(numberChannels) + " is not mono") {}

WrongSamplesPerSec::WrongSamplesPerSec(const uint32_t samplesPerSec) :
        std::invalid_argument(std::to_string(samplesPerSec) + " is not 44100") {}

WrongBytesPerSec::WrongBytesPerSec(const uint32_t bytesPerSec) :
        std::invalid_argument(std::to_string(bytesPerSec) + " is wrong bytes per sec value") {}

WrongBitesPerSample::WrongBitesPerSample(const uint16_t bitesPerSample) :
        std::invalid_argument(std::to_string(bitesPerSample) + " is wrong bytes per sec value") {}

WrongBlockAlign::WrongBlockAlign(const uint16_t blockAlign) :
        std::invalid_argument(std::to_string(blockAlign) + " is wrong block align value") {}

WrongDataChunkId::WrongDataChunkId(const uint32_t dataChunkId) :
        std::invalid_argument(std::to_string(dataChunkId) + " is not data") {}

void Reader::load(const std::string path) {
    try {
        inputFile.open(path, std::ios_base::binary);

        inputFile.read((char *) &wav, sizeof(wav::WAV));

        wav::Header headerChunk;

        while (wav.dataHeader.ChunkId != wav::DATA_CHUNK_ID) {
            inputFile.seekg(wav.dataHeader.ChunkSize, std::fstream::cur);
            inputFile.read((char *) &headerChunk, sizeof(wav::Header));
            wav.dataHeader.ChunkId = headerChunk.ChunkId;
            wav.dataHeader.ChunkSize = headerChunk.ChunkSize;
        }

        checkInput();
    }
    catch (const std::exception &e) {
        std::cout << e.what();
    }
}

bool Reader::readSample(wav::SampleBuffer *buffer) {
    inputFile.read((char *) buffer, sizeof(wav::SampleBuffer));
    if (inputFile.gcount() == 0) return false;
    return true;
}

void Reader::checkInput() {
    if (wav.RIFFHeader.ChunkId != wav::RIFF_CHUNK_ID) throw WrongRIFFChunkId(wav.RIFFHeader.ChunkId);
    else if (wav.WAVEFormat != wav::WAVE_FORMAT) throw WrongWAVEFormat(wav.WAVEFormat);
    else if (wav.FMTHeader.ChunkId != wav::FMT_CHUNK_ID) throw WrongFMTChunkId(wav.FMTHeader.ChunkId);
    else if (wav.audioFormat != wav::AUDIO_FORMAT) throw WrongAudioFormat(wav.audioFormat);
    else if (wav.numberChannels != wav::NUMBER_CHANNELS) throw WrongNumberChannels(wav.numberChannels);
    else if (wav.samplesPerSec != wav::SAMPLES_PER_SEC) throw WrongSamplesPerSec(wav.samplesPerSec);
    else if (wav.bytesPerSec != wav::BYTES_PER_SEC) throw WrongBytesPerSec(wav.bytesPerSec);
    else if (wav.bitsPerSample != wav::BITS_PER_SAMPLE) throw WrongBitesPerSample(wav.bitsPerSample);
    else if (wav.blockAlign != wav::BLOCK_ALIGN) throw WrongBlockAlign(wav.blockAlign);
    else if (wav.dataHeader.ChunkId != wav::DATA_CHUNK_ID) throw WrongDataChunkId(wav.dataHeader.ChunkId);
}

