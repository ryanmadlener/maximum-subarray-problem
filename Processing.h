#ifndef MAXIMUM_SUBARRAY_PROBLEM_PROCESSING_H
#define MAXIMUM_SUBARRAY_PROBLEM_PROCESSING_H

/**
 * @brief - The Processing class houses
 * the two algorithms used in the project,
 * the brute force algorithm and the
 * implementation of Kadane's Algorithm.
 * @param - Since the passed parameters,
 * data and size should not change, they
 * have been declared as const to avoid
 * an unforeseen errors
 */
class Processing {
    private:
        int max;
        int currentMax;

    public:
        Processing();
        int bruteForce(const int data[], const int size);
        int kadane(const int data[], const int size);
};

#endif //MAXIMUM_SUBARRAY_PROBLEM_PROCESSING_H
