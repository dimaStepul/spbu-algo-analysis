#include <iostream>
#include <utility>
#include <chrono>
#include "QuickSort.h"

void RandomArray(int *A, int n) {
    for (int i = 0; i < n; ++i) {
        A[i] = rand() % 90000 + 100000;
    }
}


void SortArray(void (*sorter)(int *, int), int *A, int n, const char *arrayname) {
    sorter(A, n);
}

void tester(void (*sorter)(int *, int),  int n, const char *name) {
    std::cout << "====== Method: " << name << "==========" << std::endl;
    int *A = new int[n];
    auto startTime = std::chrono::system_clock::now();
    std::chrono::microseconds elapsed_microseconds =
            std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - startTime);
    for (int j = 0; j < 1001; ++j) {
        n += 280;
        int *A = new int[n];
        RandomArray(A, n);
        SortArray(sorter, A, n, "Random");
        delete[] A;
        elapsed_microseconds +=
                std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - startTime);
    }
    std::cout << "TIME OF EXECUTE: ";
    std::cout << elapsed_microseconds.count() / 1001 << std::endl;
    delete[] A;
}

int main() {
    int n;
    n = 32000;
    tester(QuickSort, n, "Quick sorting");
    return 0;
}