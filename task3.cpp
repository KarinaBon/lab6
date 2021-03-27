#include <iostream>
#include <iomanip>
#include <stdlib.h>

const int min_dimension = 1;
const int max_dimension = 10;

int main() {
    // Set the dimension of the matrix
    int dimension = 0;
    std::cout << "Enter the dimension of the square matrix" << std::endl;
    while (dimension < min_dimension || dimension > max_dimension) {
        std::cout << "Number of dimension (" << min_dimension << " <= dimension <= " << max_dimension << "): ";
        std::cin >> dimension;
    }
    std::cout << std::endl;
    
    // Range of numbers in a matrix
    int random_min = 0, random_max = 0;
    std::cout << "Enter the boundaries of the random interval" << std::endl;
    while (random_min >= random_max) {
        std::cout << "Min random number: ";
        std::cin >> random_min;
        std::cout << "Max random number: ";
        std::cin >> random_max;
    }
    std::cout << std::endl;
    
    // Create a matrix with random numbers in a given range and dimension
    int **matrix = new int* [dimension];
    std::cout << "Source matrix" << std::endl;
    for (int row = 0; row < dimension; row++) {
        matrix[row] = new int [dimension];
        for (int col = 0; col < dimension; col++) {
            matrix[row][col] = random_min + rand() % (random_max - random_min + 1);
            std::cout << std::setw(5) << matrix[row][col];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Positive numbers of the corresponding row
    int positive_numbers_count[dimension]; 
    std::cout << "Positive numbers count in matrix rows" << std::endl;
    for (int row = 0; row < dimension; row++) {
        positive_numbers_count[row] = 0;
        for (int col = 0; col < dimension; col++) {
            if (matrix[row][col] <= 0) continue;
            positive_numbers_count[row] = positive_numbers_count[row] + 1;
        }
        std::cout << positive_numbers_count[row] << " ";
    }
    std::cout << std::endl << std::endl;

    // Counting the sum of numbers in a row and column and displaying on the diagonal
    for (int i = dimension - 1; i >= 0; i--) {
        int rows_cols_sum = 0;
        for (int row = 0; row < dimension; row++) {
            rows_cols_sum = rows_cols_sum + matrix[row][i];
        }
        for (int col = 0; col < dimension; col++) {
            if (col == i) continue;
            rows_cols_sum = rows_cols_sum + matrix[i][col];
        }
        matrix[i][i] = rows_cols_sum;
    }

    // Inference of the final matrix
    std::cout << "Calculated matrix" << std::endl;
    for (int row = 0; row < dimension; row++) {
        for (int col = 0; col < dimension; col++) {
            std::cout << std::setw(5) << matrix[row][col];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
