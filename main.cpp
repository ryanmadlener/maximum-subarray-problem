#include <iostream>
#include <chrono>               // For time keeping
#include "Processing.h"


// Helper functions
void runTest(int arr[], int arrSize);
void calculateTime(std::chrono::time_point<std::chrono::system_clock> startTime,
                        std::chrono::time_point<std::chrono::system_clock> endTime);

int main() {
    // Initial size of test array and the number of tests done
    // along with how many elements will be added to each test
    int arrSize = 10000;
    int numTests = 5;
    int sizeIncrement = 20000;

    // Setting the random seed
    std::srand(std::time(nullptr));

    // Loop that executes five times increasing the
    // size of the test arrays by 10,000 each time
    for (int x = 0; x < numTests; x++) {
        // Array that will be processed
        int arr[arrSize];

        // Filling the array with random number from -50 to 50
        for (int i = 0; i < arrSize; i++) {
            int randNum = (rand() % 50) - 25;
            arr[i] = randNum;
        }

        // Running the tests with the generated array
        runTest(arr, arrSize);

        // Incrementing size of array for more tests
        arrSize += sizeIncrement;
    }

    return(0);
}


/**
 * @brief - Runs both algorithms against an array
 * and calculates the time printing the results
 * to the console
 * @param arr - The array that will be processed
 * @param arrSize - The size of that array
 */
void runTest(int arr[], int arrSize) {
    // Creating the calculation object
    Processing calculate;

    // Variables for timing
    std::chrono::time_point<std::chrono::system_clock> startTime;
    std::chrono::time_point<std::chrono::system_clock> endTime;

    // Timing for the brute force algorithm
    startTime = std::chrono::high_resolution_clock::now();
    std::cout << "Brute Force: " << calculate.bruteForce(arr, arrSize) << std::endl;
    endTime = std::chrono::high_resolution_clock::now();

    // Calling function that calculates time
    calculateTime(startTime, endTime);

    // Timing for Kadane's Algorithm
    startTime = std::chrono::high_resolution_clock::now();
    std::cout << "Kadane's: " << calculate.kadane(arr, arrSize) << std::endl;
    endTime = std::chrono::high_resolution_clock::now();

    // Calling function that calculates time
    calculateTime(startTime, endTime);
}


/**
 * @brief - Function that calculates the elapsed time of
 * the function calls and prints it to the console
 * @param startTime - The starting time
 * @param endTime - The ending time
 */
void calculateTime(std::chrono::time_point<std::chrono::system_clock> startTime,
                        std::chrono::time_point<std::chrono::system_clock> endTime) {

    // Variable for time
    std::chrono::duration<double> elapsedSeconds;

    // Calculating time
    elapsedSeconds = endTime - startTime;

    std::cout << "Time in Seconds: " << elapsedSeconds.count() << std::endl << std::endl;
}
