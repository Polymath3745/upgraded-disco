#include "RecursionExamples.hpp"

int factorial(int n) {
    // Base case
    if (n == 0) {
        return 1;
    }
    // Recursive case
    return n * factorial(n - 1);
}

int fibonacci(int n) {
    if (n <= 1) {
        return n; // base case: F(0) = 0, F(1) = 1
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2); // recursive step
    }
}

int fibonacciEsque(int n) {
    if (n <= 1) {
        return n; // base case: F(0) = 0, F(1) = 1
    } else {
        return n + fibonacciEsque(n - 1) + fibonacciEsque(n - 2); // recursive step
    }
} 