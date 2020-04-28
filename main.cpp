#include <iostream>
#include "Processing.h"

int main() {
    // Creating the calculation object
    Processing calculate;

    // Initial size of test array
    int size = 1000;

    // Loop that executes five times changing the
    // size of the test arrays
    for (int x = 0; x < 5; x++) {
        int arr[size];

        for (int i = 0; i < size; i++) {
            int randNum = (rand() % 50) - 25;
            arr[i] = randNum;
        }

        // Printing out the results
        std::cout << "Kadane's: " << calculate.kadane(arr, size) << std::endl;
        std::cout << "Brute Force: " << calculate.bruteForce(arr, size) << std::endl;

        // Incrementing size of array
        size += 10000;
    }

    return(0);
}
