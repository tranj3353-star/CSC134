// ============================================================
// parser.cpp
// ============================================================

#include "parser.h"

#include <iostream>
#include <stdexcept>

// ============================================================
// CONSTRUCTOR
// ============================================================

Parser::Parser(const std::string& path)
{
    file.open(path, std::ios::binary);

    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open file");
    }

    if (!readHeader())
    {
        throw std::runtime_error("Invalid BADV file");
    }

    previousFrame.clear();
}

// ============================================================
// BASIC INFO
// ============================================================

bool Parser::isOpen() const
{
    return file.is_open();
}

const VideoHeader& Parser::getHeader() const
{
    return header;
}

// ============================================================
// HEADER
// ============================================================

bool Parser::readHeader()
{
    file.read(header.magic, 4);

    file.read(
        reinterpret_cast<char*>(&header.width),
        sizeof(uint16_t)
    );

    file.read(
        reinterpret_cast<char*>(&header.height),
        sizeof(uint16_t)
    );

    file.read(
        reinterpret_cast<char*>(&header.fps),
        sizeof(uint16_t)
    );

    file.read(
        reinterpret_cast<char*>(&header.frameCount),
        sizeof(uint32_t)
    );

    if (header.magic[0] != 'B' ||
        header.magic[1] != 'A' ||
        header.magic[2] != 'D' ||
        header.magic[3] != 'V')
    {
        return false;
    }

    return true;
}

// ============================================================
// RLE DECODE
// ============================================================

std::vector<uint8_t> Parser::rleDecode(
    const std::vector<uint8_t>& compressed)
{
    std::vector<uint8_t> output;

    for (size_t i = 0; i < compressed.size(); i += 2)
    {
        uint8_t count = compressed[i];
        uint8_t value = compressed[i + 1];

        for (uint32_t j = 0; j < count; j++)
        {
            output.push_back(value);
        }
    }

    return output;
}

// ============================================================
// XOR
// ============================================================

std::vector<uint8_t> Parser::xorBuffers(
    const std::vector<uint8_t>& a,
    const std::vector<uint8_t>& b)
{
    std::vector<uint8_t> result(a.size());

    for (size_t i = 0; i < a.size(); i++)
    {
        result[i] = a[i] ^ b[i];
    }

    return result;
}

// ============================================================
// READ FRAME
// ============================================================

bool Parser::readNextFrame(Frame& outFrame)
{
    if (!file.good())
    {
        return false;
    }

    uint8_t frameType;
    uint32_t payloadSize;

    file.read(
        reinterpret_cast<char*>(&frameType),
        sizeof(uint8_t)
    );

    if (file.eof())
    {
        return false;
    }

    file.read(
        reinterpret_cast<char*>(&payloadSize),
        sizeof(uint32_t)
    );

    std::vector<uint8_t> compressed(payloadSize);

    file.read(
        reinterpret_cast<char*>(compressed.data()),
        payloadSize
    );

    // ========================================================
    // RLE DECODE
    // ========================================================

    std::vector<uint8_t> decoded =
        rleDecode(compressed);

    // ========================================================
    // KEYFRAME
    // ========================================================

    if (frameType == 0)
    {
        outFrame.type = 0;
        outFrame.data = decoded;

        previousFrame = decoded;
    }

    // ========================================================
    // DELTA FRAME
    // ========================================================

    else if (frameType == 1)
    {
        std::vector<uint8_t> restored =
            xorBuffers(decoded, previousFrame);

        outFrame.type = 1;
        outFrame.data = restored;

        previousFrame = restored;
    }

    else
    {
        return false;
    }

    return true;
}

// ============================================================
// UNPACK BITS
// ============================================================

std::vector<uint8_t> Parser::unpackBits(
    const std::vector<uint8_t>& packed)
{
    std::vector<uint8_t> pixels;

    pixels.reserve(
        header.width * header.height
    );

    for (uint8_t byte : packed)
    {
        for (int bit = 7; bit >= 0; bit--)
        {
            uint8_t value =
                (byte >> bit) & 1;

            pixels.push_back(value);
        }
    }

    return pixels;
}