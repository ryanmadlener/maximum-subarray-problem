#include "Processing.h"

/**
 * @brief - Class constructor which initializes
 * the variables max and currentMax to zero
 */
Processing::Processing() {
    max = 0;
    currentMax = 0;
}


/**
 * @brief - The brute force implementation of
 * finding the maximum subarray.
 * @param data - The array that will be processed
 * @param size - The size of the array, used to
 * iterate over the data
 * @return - The size of the max subarray
 */
int Processing::bruteForce(const int data[], const int size) {
    // Resetting max variable
    max = 0;

    for (int i = 0; i < size; i++) {
        currentMax = 0;

        for (int x = i; x < size; x++) {
            currentMax += data[x];

            if (currentMax > max) {
                max = currentMax;
            }
        }
    }

    return(max);
}


/**
 * @brief - Implementation of Kadane's Algorithm
 * to find the Maximum Subarray.
 * @param data - The array that will be processed
 * @param size - The size of the array, used to
 * iterate over the data
 * @return - The size of the max subarray
 */
int Processing::kadane(const int data[], const int size) {
    // Resetting variables
    max = 0;
    currentMax = 0;

    for (int i = 0; i < size; i++) {
        currentMax += data[i];

        if (currentMax < 0) {
            currentMax = 0;
        }

        if (max < currentMax) {
            max = currentMax;
        }
    }

    return(max);
}