#include "./header/matrix_convertor.h"
#include "./header/pair_char_vectors.h"
#include "./header/genof_permutations_combinations.h"


int main() {

    gopc_sets_obj my_sets;

    my_sets.regel_of_sum();

    my_sets.regel_of_mul();

    std::cout << "binom = " << my_sets.regel_of_binomial_coefficients() << std::endl;
    

    my_sets.~gopc_sets_obj();
    return 0;
}