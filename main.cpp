#include <iostream>
#include <chrono>
#include "Processing.h"

int main() {
    // Creating the calculation object
    Processing calculate;

    // Initial size of test array
    int size = 1000;

    // Variables for timing
    std::chrono::time_point<std::chrono::system_clock> startTime;
    std::chrono::time_point<std::chrono::system_clock> endTime;

    // Loop that executes five times changing the
    // size of the test arrays
    for (int x = 0; x < 5; x++) {
        // Array that will be processed
        int arr[size];

        // Filling the array with random number from -50 to 50
        for (int i = 0; i < size; i++) {
            int randNum = (rand() % 50) - 25;
            arr[i] = randNum;
        }

        // Timing for the brute force algorithm
        startTime = std::chrono::high_resolution_clock::now();
        std::cout << "Brute Force: " << calculate.bruteForce(arr, size) << std::endl;
        endTime = std::chrono::high_resolution_clock::now();

        // Timing for Kadane's Algorithm
        startTime = std::chrono::high_resolution_clock::now();
        std::cout << "Kadane's: " << calculate.kadane(arr, size) << std::endl;
        endTime = std::chrono::high_resolution_clock::now();

        // Incrementing size of array
        size += 10000;
    }

    return(0);
}
