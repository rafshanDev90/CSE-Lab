#include <iostream>
using namespace std;

int binarySearch(int A[], int v, int p, int r) {
    if (p > r) {
        return -1;
    }

    int j = p + (r - p) / 2;

    if (v == A[j]) {
        return j;
    } else if (v < A[j]) {
        return binarySearch(A, v, p, j - 1);
    } else {
        return binarySearch(A, v, j + 1, r);
    }
}

int main() {
    int A[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(A) / sizeof(A[0]);
    int v;

    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    v = 23;
    int result = binarySearch(A, v, 0, n - 1);
    if (result != -1) {
        cout << "Value " << v << " found at index " << result << endl;
    } else {
        cout << "Value " << v << " not found" << endl;
    }

    v = 50;
    result = binarySearch(A, v, 0, n - 1);
    if (result != -1) {
        cout << "Value " << v << " found at index " << result << endl;
    } else {
        cout << "Value " << v << " not found" << endl;
    }

    return 0;
}
