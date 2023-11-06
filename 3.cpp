#include <iostream>
#include <vector>

unsigned long long factorial(int n) {
    std::vector<unsigned long long> factorial_values(n + 1);
    factorial_values[0] = 1; factorial_values[1] = 1;

    for (int i = 2; i <= n; ++i) {
        factorial_values[i] = factorial_values[i - 1] * i;
    } return factorial_values[n];
}

unsigned long long binomial_coefficient(int n, int k) {
    std::vector<std::vector<unsigned long long>> dp(n + 1, std::vector<unsigned long long>(k + 1, 0));

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= std::min(i, k); ++j) {
            if (j == 0 || j == i) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        }
    }

    return dp[n][k];
}


int main() {
    
    int roses = 5;
    int irises = 18;
    int roses_selected = 4;
    int irises_selected = 7;

    unsigned long long roses_ways = binomial_coefficient(roses, roses_selected);
    unsigned long long irises_ways = binomial_coefficient(irises, irises_selected);

    unsigned long long total_ways = roses_ways * irises_ways;

    std::cout << "Number of ways to create a bouquet with 4 roses and 7 irises: " << total_ways << std::endl;

    std::cout << "\n\n*********************************************************\n\n";

    int all_piople = 20; 
    int need_people = 2;  
    unsigned long long combinations = factorial(all_piople) / (factorial(need_people) * factorial(all_piople - need_people));

    std::cout << "Number of ways to choose two out of 20 people: " << combinations << std::endl;

    std::cout << "\n\n*********************************************************\n\n";

    int n = 4;
    int m = 14;
    int k = 19; 

    unsigned long long coefficient_x_n_y_m = binomial_coefficient(k, n) * binomial_coefficient(k - n, m);

    std::cout << "The quotient at x^4 * y^14 in the expansion of (1 + x + y)^19:: " << coefficient_x_n_y_m << std::endl;

        std::cout << "\n\n*********************************************************\n\n";

    return 0;
}