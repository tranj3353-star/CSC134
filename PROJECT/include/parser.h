// ============================================================
// parser.h
// ============================================================

#ifndef PARSER_H
#define PARSER_H

#include <cstdint>
#include <fstream>
#include <string>
#include <vector>

struct VideoHeader
{
    char magic[4];

    uint16_t width;
    uint16_t height;

    uint16_t fps;

    uint32_t frameCount;
};

struct Frame
{
    uint8_t type;
    std::vector<uint8_t> data;
};

class Parser
{
private:

    std::ifstream file;

    VideoHeader header;

    std::vector<uint8_t> previousFrame;

    bool readHeader();

    std::vector<uint8_t> rleDecode(
        const std::vector<uint8_t>& compressed
    );

    std::vector<uint8_t> xorBuffers(
        const std::vector<uint8_t>& a,
        const std::vector<uint8_t>& b
    );

public:

    Parser(const std::string& path);

    bool isOpen() const;

    const VideoHeader& getHeader() const;

    bool readNextFrame(Frame& outFrame);

    std::vector<uint8_t> unpackBits(
        const std::vector<uint8_t>& packed
    );
};

#endif