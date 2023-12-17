#include "./header/matrix_convertor.h"
#include "./header/pair_char_vectors.h"
#include "./header/genof_permutations_combinations.h"


int main() {

    pair_char_vectors A({'c','m','n','o','q'});
    pair_char_vectors B({'c','m','d','w'});
    pair_char_vectors C({'m','n','q'});
    pair_char_vectors D({'c','m','p'});

    pair_char_vectors result = (A.addBinary(B)).multiplyBinary(C);
    result.buildVectorFromBinary((std::string)result.getBinaryString());

    result.printBinaryString();
    result.printLetterVector();

    return 0;
}