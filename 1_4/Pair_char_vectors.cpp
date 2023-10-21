#include "Pair_char_vectors.h"

Pair_char_vectors::Pair_char_vectors(const std::vector<char>& charVector, const std::string& binary)
    : letterVector(charVector), binaryString(binary) {};

Pair_char_vectors::Pair_char_vectors(const std::vector<char>& charVector) {
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

Pair_char_vectors::Pair_char_vectors() {
letterVector = std::vector<char>();
binaryString = std::string(26, '0');
};

void Pair_char_vectors::printLetterVector() {
    std::cout << "Letters in the vector: ";
    for (char letter : letterVector) {
        std::cout << letter << " ";
    }
    std::cout << std::endl;
};

void Pair_char_vectors::printBinaryString() {
    std::cout << "Binary string: " << binaryString << std::endl;
};

Pair_char_vectors Pair_char_vectors::addBinary(const Pair_char_vectors& other) {
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

    return Pair_char_vectors(resultVector, resultBinaryString);
};

Pair_char_vectors Pair_char_vectors::denialBinary() {
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

    return Pair_char_vectors(resultVector, resultBinaryString);
};

Pair_char_vectors Pair_char_vectors::subtractBinary(const Pair_char_vectors& other) {
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

    return Pair_char_vectors(resultVector, resultBinaryString);
};

Pair_char_vectors Pair_char_vectors::multiplyBinary(const Pair_char_vectors& other) {
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

    return Pair_char_vectors(resultVector, resultBinaryString);
};

void Pair_char_vectors::buildVectorFromBinary(const std::string& binaryCode) {
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

std::string Pair_char_vectors::getBinaryString() const {
    return binaryString;
};