#include "Pair_char_vectors.h"

#include "matrix_convertor.h"

int main() {

    // std::vector<char> charVectorA = {'b','d','l','p'};
    // Pair_char_vectors A(charVectorA);

    // std::vector<char> charVectorB = {'b','d','e','l','p','x'};
    // Pair_char_vectors B(charVectorB);

    // std::vector<char> charVectorC = {'k','l','p','t'};
    // Pair_char_vectors C(charVectorC);

    // std::vector<char> charVectorD = {'d','k','o','p','q','u','v'};
    // Pair_char_vectors D(charVectorD);

    // Pair_char_vectors result = A.subtractBinary(B).multiplyBinary(C.addBinary(D));
    // result.buildVectorFromBinary((std::string)result.getBinaryString());

    // result.printBinaryString();
    // result.printLetterVector();

    matrix_converter matrix(4, 4);

    std::vector<std::vector<int>> input_matrix = {
        {0,1,1,1},
        {0,0,1,0},
        {0,1,0,0},
        {0,0,0,0}
    };

    matrix.set_matrix(input_matrix);
    std::cout<<"Initial matrix:\n";
    matrix.print_matrix();

    matrix_converter matrix_reflexivity = matrix.matrix_modification_reflexivity();
    std::cout<<"\nReflexivity matrix:\n";
    matrix_reflexivity.print_matrix();

    matrix_converter matrix_symmetric = matrix.matrix_modification_symmetric();
    std::cout<<"\nSymmetric matrix:\n";
    matrix_symmetric.print_matrix();

    matrix_converter matrix_transitive = matrix.matrix_modification_transitive();
    std::cout<<"\nTransitive matrix:\n";
    matrix_transitive.print_matrix();

    matrix_converter matrix_transitive_warshall = matrix.matrix_modification_transitive_warshall();
    std::cout<<"\nTransitive warshall matrix:\n";
    matrix_transitive_warshall.print_matrix();

    matrix.create_matrix_power();
    matrix_reflexivity.create_matrix_power();
    matrix_symmetric.create_matrix_power();
    matrix_transitive.create_matrix_power();
    matrix_transitive_warshall.create_matrix_power();

    if (matrix_transitive.get_power() == matrix_transitive_warshall.get_power()){

        std::cout << "\nMatrix transitive good!\n";
    } else {

        throw std::logic_error ("The two methods are not transitive with each other.");
    }
    
    std::cout << "\nFinal power = "<< (int)(matrix.get_power()+
    matrix_reflexivity.get_power() + matrix_symmetric.get_power()
    + matrix_transitive.get_power()) << "\nСonsists of -> " << matrix.get_power()
    << " + " << matrix_reflexivity.get_power() << " + " << matrix_symmetric.get_power()
    << " + " << matrix_transitive.get_power();

    std::cout<< "\n\n";
    return 0;
    
}