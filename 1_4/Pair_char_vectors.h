#pragma once

#include <iostream>
#include <vector>
#include <string>

class Pair_char_vectors {
public:

    Pair_char_vectors(const std::vector<char>& charVector);

    Pair_char_vectors();

    void printLetterVector();

    void printBinaryString();

    Pair_char_vectors addBinary(const Pair_char_vectors& other);

    Pair_char_vectors denialBinary();

    Pair_char_vectors subtractBinary(const Pair_char_vectors& other);

    Pair_char_vectors multiplyBinary(const Pair_char_vectors& other);

    void buildVectorFromBinary(const std::string& binaryCode);

    std::string getBinaryString() const;

private:
    Pair_char_vectors(const std::vector<char>& charVector, const std::string& binary);

    std::vector<char> letterVector;
    std::string binaryString;
};