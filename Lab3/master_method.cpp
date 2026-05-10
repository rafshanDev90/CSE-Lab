#include <iostream>
#include <cmath>
using namespace std;

void masterMethod(int a, int b, int n, string f_n) {
    double c = log(a) / log(b);
    cout << "T(n) = " << a << "T(n/" << b << ") + " << f_n << endl;
    cout << "c = log_" << b << "(" << a << ") = " << c << endl;
    cout << endl;
}

int main() {
    cout << "Master Method Examples" << endl;
    cout << "======================" << endl;
    cout << endl;

    cout << "Example 1: T(n) = 2T(n/2) + n" << endl;
    masterMethod(2, 2, 0, "n");
    cout << "f(n) = n = n^1, c = 1" << endl;
    cout << "Case 2: f(n) = Θ(n^c)" << endl;
    cout << "Solution: T(n) = Θ(n log n)" << endl;
    cout << endl;

    cout << "Example 2: T(n) = 4T(n/2) + n" << endl;
    masterMethod(4, 2, 0, "n");
    cout << "f(n) = n = n^1, c = log_2(4) = 2" << endl;
    cout << "Since 1 < 2 - ε (ε = 1)" << endl;
    cout << "Case 1: f(n) = O(n^(c - ε))" << endl;
    cout << "Solution: T(n) = Θ(n^2)" << endl;
    cout << endl;

    cout << "Example 3: T(n) = T(n/2) + 1" << endl;
    masterMethod(1, 2, 0, "1");
    cout << "f(n) = 1 = n^0, c = log_2(1) = 0" << endl;
    cout << "Case 2: f(n) = Θ(n^c)" << endl;
    cout << "Solution: T(n) = Θ(log n)" << endl;
    cout << endl;

    cout << "Example 4: T(n) = 3T(n/4) + n log n" << endl;
    masterMethod(3, 4, 0, "n log n");
    cout << "f(n) = n log n, c = log_4(3) ≈ 0.79" << endl;
    cout << "Since n log n grows faster than n^0.79" << endl;
    cout << "Case 3: f(n) = Ω(n^(c + ε))" << endl;
    cout << "Solution: T(n) = Θ(n log n)" << endl;

    return 0;
}
