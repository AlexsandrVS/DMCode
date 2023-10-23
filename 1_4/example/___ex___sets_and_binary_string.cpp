#include "./header/pair_char_vectors.h"

int main (){

    std::vector<char> charVectorA = {'b','d','l','p'};
    pair_char_vectors A(charVectorA);

    std::vector<char> charVectorB = {'b','d','e','l','p','x'};
    pair_char_vectors B(charVectorB);

    std::vector<char> charVectorC = {'k','l','p','t'};
    pair_char_vectors C(charVectorC);

    std::vector<char> charVectorD = {'d','k','o','p','q','u','v'};
    pair_char_vectors D(charVectorD);

    pair_char_vectors result = A.subtractBinary(B).multiplyBinary(C.addBinary(D));
    result.buildVectorFromBinary((std::string)result.getBinaryString());

    result.printBinaryString();
    result.printLetterVector();

}