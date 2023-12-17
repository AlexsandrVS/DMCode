#pragma once

#include "a_libdm.h"
#include <limits>
#include <algorithm>


class gopc_sets_obj {
public:
    gopc_sets_obj();
    gopc_sets_obj(int_fast16_t count_k, const std::vector<char> &vec_k, int_fast16_t count_n, const std::vector<char> &vec_n);
    ~gopc_sets_obj();

    void choise_of_gopc_sets_obj(); //! TODO? it's menu 

    int regel_of_sum();
    int regel_of_mul();


    int regel_of_placement_n_by_k_elements(); //! TODO
    int regel_of_placement_n_by_k_with_repetition(); //! TODO

    int regel_of_combination(); //! TODO
    int regel_of_combination_without_repetition(); //! TODO

    int regel_of_shuffling(); //! TODO
    int regel_of_shuffling_without_repetition(); //! TODO

    unsigned long long regel_of_binomial_coefficients();

    void sort_by_lexicographic_order();

    short get_power_n();
    short get_power_k();
    unsigned get_power();

    int factorial(int n);

private:
    int_fast16_t count_vector_k;
    std::vector<char> vector_k;

    int_fast16_t count_vector_n;
    std::vector<char> vector_n;

    short power_k{};
    short power_n{};

    unsigned power{};
};



gopc_sets_obj::gopc_sets_obj() {
    std::cout << "Введите размер вектора k: ";
    std::cin >> count_vector_k;

    while (count_vector_k < 1 || std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Неверный ввод. Размер должен быть положительным целым числом. Попробуйте снова: ";
        std::cin >> count_vector_k;
    }

    vector_k.resize(count_vector_k);
    std::cout << "\nВведите элементы вектора k:\n";
    for (int i = 0; i < count_vector_k; ++i) {
        std::cin >> vector_k[i];
    }

    power_k = std::count_if(vector_k.begin(), vector_k.end(), [](char c) { return c != '\0'; });

    std::cout << "\nВведите размер вектора n: ";
    std::cin >> count_vector_n;
    while (count_vector_n < 1 || std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Неверный ввод. Размер должен быть положительным целым числом. Попробуйте снова: ";
        std::cin >> count_vector_n;
    }

    vector_n.resize(count_vector_n);
    std::cout << "\nВведите элементы вектора n:\n";
    for (int i = 0; i < count_vector_n; ++i) {
        std::cin >> vector_n[i];
    }

    power_n = std::count_if(vector_n.begin(), vector_n.end(), [](char c) { return c != '\0'; });
}


gopc_sets_obj::gopc_sets_obj(int_fast16_t count_k, const std::vector<char>& vec_k, int_fast16_t count_n, const std::vector<char>& vec_n)
        : count_vector_k(count_k), vector_k(vec_k), count_vector_n(count_n), vector_n(vec_n) {
        
        power_k = std::count_if(vector_k.begin(), vector_k.end(), [](char c) { return c != '0'; });
        power_n = std::count_if(vector_n.begin(), vector_n.end(), [](char c) { return c != '0'; });
    }


gopc_sets_obj::~gopc_sets_obj() {
    vector_k.clear();
    vector_n.clear();
}


int gopc_sets_obj::regel_of_sum() {
    std::vector<char> result;
    result = vector_k;
    bool has_common_elements = false;
    for (const char& elem : vector_k) {
        if (std::find(vector_n.begin(), vector_n.end(), elem) != vector_n.end()) {
            has_common_elements = true;
            break;
        }
    }
    if (!has_common_elements) {
        result = vector_k;
        for (const char& elem : vector_n) {
            if (std::find(result.begin(), result.end(), elem) == result.end()) {
                result.push_back(elem);
            }
        }
        power = result.size();
        std::cout << "Power sum = " << power << std::endl;
    } else {
        std::cout << "Vectors contain common elements. Cannot perform the addition operation." << std::endl;
        power = 0;
    }
    return power;
}

int gopc_sets_obj::regel_of_mul() {
    bool has_common_elements = false;
    for (const char& elem : vector_k) {
        if (std::find(vector_n.begin(), vector_n.end(), elem) != vector_n.end()) {
            has_common_elements = true;
            break;
        }
    }

    if (!has_common_elements) {
        power = power_k * power_n;
        std::cout << "Power mul = " << power << std::endl;
    } else {
        std::cout << "Vectors cannot be multiplied because they contain common elements." << std::endl;
        power = 0;
    }
    
    return power;
}



unsigned long long gopc_sets_obj::regel_of_binomial_coefficients() {
    if (power_n >= power_k) {
        short n_minus_k = power_n - power_k;
        unsigned long long result = 1;
        
        for (int i = 1; i <= power_k; ++i) {
            result *= power_n - power_k + i;
            result /= i;
        }
        
        return result;
    } else {
        std::cout << "Error: (n - k) does not exist. Make sure n is greater than or equal to k." << std::endl;
        return -1;
    }
}

void gopc_sets_obj::sort_by_lexicographic_order() {
    std::sort(vector_k.begin(), vector_k.end());
    std::sort(vector_n.begin(), vector_n.end());
}

short gopc_sets_obj::get_power_n()
{
    return power_n;
}

short gopc_sets_obj::get_power_k()
{
    return power_k;
}

unsigned gopc_sets_obj::get_power()
{
    return power;
}

int gopc_sets_obj::factorial(int n) {
    int f = 1;

        while (n > 1) {
                for(int i=3;i<=n;i+=2) 
                        f *= i;
                n >>= 1;
                f <<= n;
        }

        return f;
}



