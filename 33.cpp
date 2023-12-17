#include <iostream>

// Функция для вычисления биномиального коэффициента C(n, k)
unsigned long long binomialCoefficient(int n, int k) {
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;

    unsigned long long result = 1;
    k = std::min(k, n - k);

    for (int i = 0; i < k; ++i) {
        result *= (n - i);
        result /= (i + 1);
    }

    return result;
}

int main() {
    int n = 4;  // Значение n
    int m = 14; // Значение m
    int k = 19; // Значение k

    // Вычисляем биномиальные коэффициенты
    unsigned long long coefficient_x_n_y_m = binomialCoefficient(k, n) * binomialCoefficient(k, m);

    std::cout << "Коэффициент при x^4 * y^14 в разложении (1 + x + y)^19: " << coefficient_x_n_y_m << std::endl;

    return 0;
}
