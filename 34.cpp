#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

// Функция для вывода матрицы смежности
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

// Функция для проверки, являются ли два графа изоморфными
bool areIsomorphic(const std::vector<std::vector<int>>& graph1, const std::vector<std::vector<int>>& graph2) {
    // Сравниваем матрицы смежности графов
    return graph1 == graph2;
}

// Функция для генерации всех перестановок
void generateAllPermutations(std::vector<int>& arr, std::vector<std::vector<int>>& permutations, int currentIndex) {
    if (currentIndex == arr.size()) {
        permutations.push_back(arr);
        return;
    }

    for (int i = currentIndex; i < arr.size(); ++i) {
        std::swap(arr[currentIndex], arr[i]);
        generateAllPermutations(arr, permutations, currentIndex + 1);
        std::swap(arr[currentIndex], arr[i]);
    }
}

int main() {
    std::vector<std::vector<int>> originalGraph = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };

    // Генерируем все перестановки вершин исходного графа
    std::vector<int> vertexPermutation(originalGraph.size());
    for (int i = 0; i < originalGraph.size(); ++i) {
        vertexPermutation[i] = i;
    }

    std::vector<std::vector<int>> allPermutations;
    generateAllPermutations(vertexPermutation, allPermutations, 0);

    // Множество для отслеживания изоморфных графов
    std::set<std::vector<std::vector<int>>> isomorphicGraphs;

    // Создаем графы на основе перестановок и проверяем их на изоморфизм
    for (const auto& permutation : allPermutations) {
        std::vector<std::vector<int>> permutedGraph(originalGraph.size(), std::vector<int>(originalGraph.size(), 0));

        for (int i = 0; i < originalGraph.size(); ++i) {
            for (int j = 0; j < originalGraph.size(); ++j) {
                permutedGraph[permutation[i]][permutation[j]] = originalGraph[i][j];
            }
        }

        if (areIsomorphic(originalGraph, permutedGraph) && originalGraph != permutedGraph) {
            isomorphicGraphs.insert(permutedGraph);
        }
    }

    // Выводим изоморфные графы
    bool foundIsomorph = false;
    for (const auto& graph : isomorphicGraphs) {
        if (areIsomorphic(originalGraph, graph)) {
            if (!foundIsomorph) {
                std::cout << "Исходный граф:" << std::endl;
                printMatrix(graph);
                std::cout << std::endl;
                foundIsomorph = true;
            }
            std::cout << "Найден изоморфный граф:" << std::endl;
            printMatrix(graph);
        }
    }

    if (!foundIsomorph) {
        std::cout << "Изоморфных графов не найдено." << std::endl;
    }

    return 0;
}