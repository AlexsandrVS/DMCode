#pragma once

#include "a_libdm.h"

class pair_char_vectors {
public:

    pair_char_vectors(const std::vector<char>& charVector);

    pair_char_vectors();

    void printLetterVector();

    void printBinaryString();

    pair_char_vectors addBinary(const pair_char_vectors& other);

    pair_char_vectors denialBinary();

    pair_char_vectors subtractBinary(const pair_char_vectors& other);

    pair_char_vectors multiplyBinary(const pair_char_vectors& other);

    void buildVectorFromBinary(const std::string& binaryCode);

    std::string getBinaryString() const;

private:
    pair_char_vectors(const std::vector<char>& charVector, const std::string& binary);

    std::vector<char> letterVector;
    std::string binaryString;
};


pair_char_vectors::pair_char_vectors(const std::vector<char>& charVector, const std::string& binary)
    : letterVector(charVector), binaryString(binary) {};

pair_char_vectors::pair_char_vectors(const std::vector<char>& charVector) {
    if (charVector.size() > 26) {
        std::cerr << "Error: Character vector exceeds 26 positions." << std::endl;
        return;
    }

    letterVector = charVector;
    binaryString = std::string(26, '0');

    for (char letter : charVector) {
        if (std::isalpha(letter) && std::islower(letter)) {
            int position = letter - 'a';
            binaryString[position] = '1';
        }
    }
};

pair_char_vectors::pair_char_vectors() {
    letterVector = std::vector<char>();
    binaryString = std::string(26, '0');
};

void pair_char_vectors::printLetterVector() {
    std::cout << "Letters in the vector: ";
    for (char letter : letterVector) {
        std::cout << letter << " ";
    }
    std::cout << std::endl;
};

void pair_char_vectors::printBinaryString() {
    std::cout << "Binary string: " << binaryString << std::endl;
};

pair_char_vectors pair_char_vectors::addBinary(const pair_char_vectors& other) {
    std::vector<char> resultVector;
    std::string resultBinaryString;

    for (int i = 0; i < 26; ++i) {
        if (binaryString[i] == '1' || other.binaryString[i] == '1') {
            resultVector.push_back('a' + i);
            resultBinaryString += '1';
        } else {
            resultBinaryString += '0';
        }
    }

    return pair_char_vectors(resultVector, resultBinaryString);
};

pair_char_vectors pair_char_vectors::denialBinary() {
    std::vector<char> resultVector;
    std::string resultBinaryString;

    for (int i = 0; i < 26; ++i) {
        if (binaryString[i] == '0') {
            resultVector.push_back('a' + i);
            resultBinaryString += '1';
        } else {
            resultBinaryString += '1';
        }
    }

    return pair_char_vectors(resultVector, resultBinaryString);
};

pair_char_vectors pair_char_vectors::subtractBinary(const pair_char_vectors& other) {
    std::vector<char> resultVector;
    std::string resultBinaryString;

    for (int i = 0; i < 26; ++i) {
        if (binaryString[i] == '1' && other.binaryString[i] == '0') {
            resultVector.push_back('a' + i);
            resultBinaryString += '1';
        } else {
            resultBinaryString += '0';
        }
    }

    return pair_char_vectors(resultVector, resultBinaryString);
};

pair_char_vectors pair_char_vectors::multiplyBinary(const pair_char_vectors& other) {
    std::vector<char> resultVector;
    std::string resultBinaryString;

    for (int i = 0; i < 26; ++i) {
        if (binaryString[i] == '1' && other.binaryString[i] == '1') {
            resultVector.push_back('a' + i);
            resultBinaryString += '1';
        } else {
            resultBinaryString += '0';
        }
    }

    return pair_char_vectors(resultVector, resultBinaryString);
};

void pair_char_vectors::buildVectorFromBinary(const std::string& binaryCode) {
    if (binaryCode.size() != 26) {
        std::cerr << "Error: Binary code must be 26 characters long." << std::endl;
        return;
    }

    letterVector.clear();

    for (int i = 0; i < 26; ++i) {
        if (binaryCode[i] == '1') {
            letterVector.push_back('a' + i);
        }
    }
    binaryString = binaryCode;
};

std::string pair_char_vectors::getBinaryString() const {
    return binaryString;
};