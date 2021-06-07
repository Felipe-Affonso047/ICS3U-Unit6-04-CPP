// Copyright (c) 2021 Felipe Affonso All rights reserved
//
// Created by: Felipe Affonso
// Created on: June 2021
// This program generate random numbers and uses a 2d array to get the average

#include <iostream>
#include <cmath>
#include <iomanip>
#include <random>
#include <array>

template <int rows, int cols>
float twodListAverage(int (&listOfNumbers)[rows][cols]) {
    // This function get a 2d array average
    float average = 0;
    int counter = 0;

    for (int rowCounter = 0; rowCounter < rows; rowCounter++) {
        for (int columnCounter = 0;
            columnCounter < cols;
            columnCounter++) {
            average += listOfNumbers[rowCounter][columnCounter];
            counter = counter + 1;
        }
    }

    average = average / counter;

    return average;
}

int main() {
    // This function is the main function and generate random numbers
    float average;
    const int rows = 4;
    const int columns = 4;

    int numbers[rows][columns];

    for (int rowCounter = 0; rowCounter < rows; rowCounter ++) {
        for (int columnCounter = 0; columnCounter < columns; columnCounter ++) {
            int randomNumber;
            std::random_device rseed;
            std::mt19937 rgen(rseed());
            std::uniform_int_distribution<int> idist(0, 50);
            randomNumber = idist(rgen);
            std::cout << randomNumber << " ";
            numbers[rowCounter][columnCounter] = randomNumber;
        }
        std::cout << std::endl;
    }

    average = twodListAverage(numbers);

    std::cout << "\nThe average is: " << average << std::endl;

    std::cout << "\nDone." << std::endl;
}
