#include "./header/matrix_convertor.h"
#include "./header/pair_char_vectors.h"
#include "./header/genof_permutations_combinations.h"


int main() {

    std::vector<char> vector_k(5, 'R');
    std::vector<char> vector_n(18, 'I');

    gopc_sets_obj sets_obj(vector_k.size(), vector_k, vector_n.size(), vector_n);

    std::cout << sets_obj.get_power_k() << std::endl;
    std::cout << sets_obj.get_power_n() << std::endl;

    sets_obj.regel_of_sum();
    sets_obj.regel_of_mul();
    sets_obj.regel_of_binomial_coefficients();

    return 0;
}