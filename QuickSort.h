
#include <chrono>
#include <utility>


template<typename T>
void QuickSortRec(T *A, int n) {
    int left = 0, right = n - 1;
    int p_ind = left + (right - left) / 2;
    T p = A[p_ind];
    int i = left, j = right;
    while (i < j) {
        while (A[i] < p) {
            ++i;
        }
        while (p < A[j]) {
            --j;
        }
        if (i < j) {
            std::swap(A[i], A[j]);
            ++i;
            --j;
        } else if (i == j) {
            ++i;
            --j;
        }
    }
    if (p_ind < i) {
        if (i < right) QuickSortRec(A + i, right - i + 1);
        if (j > left) QuickSortRec(A + left, j - left + 1);
    } else {
        if (j > left) QuickSortRec(A + left, j - left + 1);
        if (i < right) QuickSortRec(A + i, right - i + 1);
    }
}

template<typename T>
void QuickSort(T *A, int n) {
    auto startTime = std::chrono::system_clock::now();
    int N = n, size = 1;
    while (N > 0) {
        N >>= 1;
        ++size;
    }
    int *StackLeft = new int[size];
    int *StackRight = new int[size];
    int LastInStack = -1;
    ++LastInStack;
    StackLeft[LastInStack] = 0;
    StackRight[LastInStack] = n - 1;
    while (LastInStack > -1) {
        int left = StackLeft[LastInStack];
        int right = StackRight[LastInStack];
        --LastInStack;
        int pIndex = left + (right - left) / 2;
        T p = A[pIndex];
        int i = left, j = right;
        while (i < j) {
            while (A[i] < p) {
                ++i;
            }
            while (p < A[j]) {
                --j;
            }
            if (i < j) {
                std::swap(A[i], A[j]);
                ++i;
                --j;
            } else if (i == j) {
                ++i;
                --j;
            }
        }
        if (i > pIndex) {
            if (j > left) {
                ++LastInStack;
                StackLeft[LastInStack] = left;
                StackRight[LastInStack] = j;
            }
            if (i < right) {
                ++LastInStack;
                StackLeft[LastInStack] = i;
                StackRight[LastInStack] = right;
            }
        } else {
            if (i < right) {
                ++LastInStack;
                StackLeft[LastInStack] = i;
                StackRight[LastInStack] = right;
            }
            if (j > left) {
                ++LastInStack;
                StackLeft[LastInStack] = left;
                StackRight[LastInStack] = j;
            }
        }
    }
    delete[] StackLeft;
    delete[] StackRight;
    std::chrono::microseconds elapsed_microseconds =
            std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - startTime);
    std::cout << "TIME OF EXECUTE: ";
    std::cout << elapsed_microseconds.count() << std::endl;
}
