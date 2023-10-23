#pragma once

#include "a_libdm.h"


class gopc_sets_obj {
public:
    gopc_sets_obj(); //! TODO
    ~gopc_sets_obj(); //! TODO

    void choise_of_gopc_sets_obj(); //! TODO? it's menu 

    int regel_of_sum(); //! TODO
    int regel_of_mul(); //! TODO

    int regel_of_placement_n_by_k_elements(); //! TODO
    int regel_of_placement_n_by_k_with_repetition(); //! TODO

    int regel_of_combination(); //! TODO
    int regel_of_combination_without_repetition(); //! TODO

    int regel_of_shuffling(); //! TODO
    int regel_of_shuffling_without_repetition(); //! TODO

    int regel_of_binomial_coefficients(); //! TODO

    void sort_by_lexicographic_order(); //! TODO

    short get_power_n(); //! TODO
    short get_power_k(); //! TODO
    unsigned get_power();

private:
    int_fast16_t count_vector_k;
    std::vector<char> vector_k;

    int_fast16_t count_vector_n;
    std::vector<char> vector_n;

    short power_k{};
    short power_n{};

    unsigned power{};
    
};

gopc_sets_obj::gopc_sets_obj()
{
}

gopc_sets_obj::~gopc_sets_obj()
{
}

unsigned gopc_sets_obj::get_power()
{
    return power;
}
