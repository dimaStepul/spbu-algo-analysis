#include <iostream>
#include <utility>

#include "QuickSort.h"

void RandomArray(int *A, int n) {
    for (int i = 0; i < n; ++i) {
        A[i] = rand() % 90000 + 100000;
    }
}


void SortArray(void (*sorter)(int *, int), int *A, int n, const char *arrayname) {
    std::cout << "--- Array: " << arrayname << " ; ";
    sorter(A, n);
}

void tester(void (*sorter)(int *, int), const int *R, int n, const char *name) {
    std::cout << "====== Method: " << name << "==========" << std::endl;
    int *A = new int[n];

    for (int i = 0; i < n; ++i) A[i] = R[i];
    SortArray(sorter, A, n, "Random");


    delete[] A;
}

int main() {
    int n;
    do {
        std::cout << "Array size: ";
        std::cin >> n;
        std::cout << std::endl;
    } while (n < 1);
    int *A = new int[n];
    RandomArray(A, n);


//    tester(QuickSortRec, A, n, "Quick Rec sorting");
    tester(QuickSort, A, n, "Quick sorting");


    delete[] A;
    return 0;
}