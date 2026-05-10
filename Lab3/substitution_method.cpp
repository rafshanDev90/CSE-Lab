#include <iostream>
#include <cmath>
using namespace std;

int recurrenceT(int n) {
    if (n == 1) {
        return 1;
    }
    return 2 * recurrenceT(n / 2) + n;
}

int main() {
    cout << "Substitution Method Example" << endl;
    cout << "Recurrence: T(n) = 2T(n/2) + n" << endl;
    cout << "Solution: T(n) = O(n log n)" << endl;
    cout << endl;

    cout << "Testing values of T(n):" << endl;
    for (int n = 1; n <= 16; n *= 2) {
        cout << "T(" << n << ") = " << recurrenceT(n) << endl;
    }

    cout << endl;
    cout << "Verification with n*log(n):" << endl;
    for (int n = 1; n <= 16; n *= 2) {
        double expected = n * log2(n);
        cout << "n = " << n << ", n*log(n) = " << expected << ", T(n) = " << recurrenceT(n) << endl;
    }

    return 0;
}
