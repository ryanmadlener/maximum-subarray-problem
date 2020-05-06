#include <iostream>
#include <fstream>
#include <chrono>               // For time keeping
#include "Processing.h"


// Helper functions
void runTest(int arr[], int arrSize, std::ofstream& output);
std::chrono::duration<double> calculateTime(std::chrono::time_point<std::chrono::system_clock> startTime,
                        std::chrono::time_point<std::chrono::system_clock> endTime);

int main() {
    // Initial size of test array and the number of tests done
    // along with how many elements will be added to each test
    int arrSize = 10000;
    int numTests = 5;
    int sizeIncrement = 20000;

    // ofstream for output file
    std::ofstream output("output.txt");

    // Checking to make sure file opens
    if (!output) {
        std::cout << "Error. Unable to open output file" << std::endl;
        return(-1);
    }

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
        runTest(arr, arrSize, output);

        // Incrementing size of array for more tests
        arrSize += sizeIncrement;
    }

    return(0);
}


/**
 * @brief - Runs both algorithms against an array
 * and calculates the time printing the results
 * to a file
 * @param arr - The array that will be processed
 * @param arrSize - The size of that array
 * @param output - The ofstream that outputs
 * the results to a file
 */
void runTest(int arr[], int arrSize, std::ofstream& output) {
    output << "Array Size: " << arrSize << std::endl;

    // Creating the calculation object
    Processing calculate;

    // Variables for timing
    std::chrono::time_point<std::chrono::system_clock> startTime;
    std::chrono::time_point<std::chrono::system_clock> endTime;
    std::chrono::duration<double> elapsedSeconds;

    // Timing for the brute force algorithm
    startTime = std::chrono::high_resolution_clock::now();
    output << " Brute Force: " << calculate.bruteForce(arr, arrSize) << std::endl;
    endTime = std::chrono::high_resolution_clock::now();

    // Calling function that calculates time
    elapsedSeconds = calculateTime(startTime, endTime);
    output << " Time in Seconds: " << elapsedSeconds.count() << std::endl;

    // Timing for Kadane's Algorithm
    startTime = std::chrono::high_resolution_clock::now();
    output << " Kadane's: " << calculate.kadane(arr, arrSize) << std::endl;
    endTime = std::chrono::high_resolution_clock::now();

    // Calling function that calculates time
    elapsedSeconds = calculateTime(startTime, endTime);
    output << " Time in Seconds: " << elapsedSeconds.count() << std::endl << std::endl;
}


/**
 * @brief - Function that calculates the elapsed time of
 * the function calls and prints it to the console
 * @param startTime - The starting time
 * @param endTime - The ending time
 * @return - The elapsed seconds
 */
std::chrono::duration<double> calculateTime(std::chrono::time_point<std::chrono::system_clock> startTime,
                        std::chrono::time_point<std::chrono::system_clock> endTime) {

    return(endTime - startTime);
}
