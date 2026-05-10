#include <iostream>
#include <cmath>
using namespace std;

void printRecursionTree(int n, int level) {
    if (n == 1) {
        for (int i = 0; i < level; i++) {
            cout << "  ";
        }
        cout << "T(1) = 1" << endl;
        return;
    }

    for (int i = 0; i < level; i++) {
        cout << "  ";
    }
    cout << "T(" << n << ") = 2T(" << n/2 << ") + " << n << endl;

    printRecursionTree(n / 2, level + 1);
    printRecursionTree(n / 2, level + 1);
}

int main() {
    cout << "Recursion-Tree Method Example" << endl;
    cout << "Recurrence: T(n) = 2T(n/2) + n" << endl;
    cout << "Solution: T(n) = O(n log n)" << endl;
    cout << endl;

    cout << "Recursion Tree for T(8):" << endl;
    printRecursionTree(8, 0);

    cout << endl;
    cout << "Cost at each level:" << endl;
    cout << "Level 0: n = 8" << endl;
    cout << "Level 1: n/2 + n/2 = 8" << endl;
    cout << "Level 2: n/4 + n/4 + n/4 + n/4 = 8" << endl;
    cout << "Level 3: 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 = 8" << endl;
    cout << endl;
    cout << "Total cost: n * log(n) = 8 * 3 = 24" << endl;

    return 0;
}
