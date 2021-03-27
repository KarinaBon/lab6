#include <iostream>
#include <iomanip>
#include <cstdlib>

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
    int matrix[dimension][dimension];
    std::cout << "Source matrix" << std::endl;
    for (int row = 0; row < dimension; row++) {
        for (int col = 0; col < dimension; col++) {
            matrix[row][col] = random_min + rand() % (random_max - random_min + 1);
            std::cout << std::setw(5) << matrix[row][col];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Add the first and last lines of the square array
    for (int i = dimension - 1; i >= 0; i--) {
        matrix[i][dimension - 1] = matrix[0][i] + matrix[dimension - 1][i];
    }

    // Writes the result to the last column in a matrix
    std::cout << "Calculated matrix" << std::endl;
    for (int row = 0; row < dimension; row++) {
        for (int col = 0; col < dimension; col++) {
            std::cout << std::setw(5) << matrix[row][col];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
