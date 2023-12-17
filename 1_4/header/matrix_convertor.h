#pragma once

#include "a_libdm.h"

class matrix_converter {
public:
    matrix_converter(int num_rows, int num_cols);

    void print_matrix() const;

    std::vector<std::vector<int>> get_matrix() const;

    void set_matrix(const std::vector<std::vector<int>>& input_matrix);

    matrix_converter matrix_modification_reflexivity() const;

    matrix_converter matrix_modification_symmetric() const;

    matrix_converter matrix_modification_transitive() const;

    matrix_converter matrix_modification_transitive_warshall() const;

    void create_matrix_power();

    int& operator()(int row, int col);

    const int& operator()(int row, int col) const;

    int get_rows() const;

    int get_cols() const;

    int get_power() const;

private:
    int rows;
    int cols;
    int power{};
    std::vector<std::vector<int>> data; // Матрица
};

matrix_converter::matrix_converter(int num_rows, int num_cols) : rows(num_rows), cols(num_cols) {
        data.resize(rows, std::vector<int>(cols, 0)); // Инициализация матрицы с нулевыми значениями
}

void matrix_converter::print_matrix() const {
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            std::cout << data[row][col] << " "; // Вывод элемента матрицы
        }
        std::cout << std::endl; // Переход на новую строку
    }
}

std::vector<std::vector<int>> matrix_converter::get_matrix() const {
    return data;
}

void matrix_converter::set_matrix(const std::vector<std::vector<int>>& input_matrix) {
    // Проверка размеров входной матрицы
    if (input_matrix.size() != rows || input_matrix[0].size() != cols) {
        throw std::invalid_argument("Invalid matrix dimensions");
    }
    data = input_matrix; // Установка новой матрицы
}

matrix_converter matrix_converter::matrix_modification_reflexivity() const {

    matrix_converter new_matrix = *this; // Создаем копию матрицы

        // Модифицируем диагональные элементы
        for(int i = 0; i < std::min(rows, cols); ++i) {
            new_matrix(i,i) = 1;
        }

    return new_matrix;
}

matrix_converter matrix_converter::matrix_modification_symmetric() const {
    if (rows != cols) {
        throw std::invalid_argument("The matrix must be square to make it symmetric.");
    }

    matrix_converter new_matrix = *this; // Создаем копию матрицы
    // Симметричное расположения элементов
    for(int i = 0; i < rows; ++i) {
        for(int j = i+1; j < cols; ++j) {
            new_matrix(j,i) = new_matrix(i,j);
        }
    }

    return new_matrix;
}

matrix_converter matrix_converter::matrix_modification_transitive() const {
    if (rows != cols) {
        throw std::invalid_argument("The matrix must be square to compute transitive new_matrix using matrix multiplication and addition.");
    }

    matrix_converter new_matrix = *this; // Создаем копию исходной матрицы
    
    for (int k = 0; k < cols; ++k) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (new_matrix(i, k) != 0 && new_matrix(k, j) != 0) {
                    new_matrix(i, j) = 1;
                }
            }
        }
    } return new_matrix;
}

matrix_converter matrix_converter::matrix_modification_transitive_warshall() const {
    if (rows != cols) {
        throw std::invalid_argument("The matrix must be square to compute transitive new_matrix using the Warshall algorithm.");
    }

    matrix_converter new_matrix = *this; // Создаем копию исходной матрицы

    for (int k = 0; k < cols; ++k) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                new_matrix(i, j) = new_matrix(i, j) || (new_matrix(i, k) && new_matrix(k, j));
            }
        }
    }

    return new_matrix;
}

void matrix_converter::create_matrix_power() {
    int count = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (data[i][j] != 0) {
                count++;
            }
        }
    }
    power = count;
}

int& matrix_converter::operator()(int row, int col) {
    // Проверка на выход за границы матрицы
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[row][col];
}

const int& matrix_converter::operator()(int row, int col) const {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[row][col];
}

int matrix_converter::get_rows() const {
    return rows;
}

int matrix_converter::get_cols() const {
    return cols;
}

int matrix_converter::get_power() const {
    return power;
}