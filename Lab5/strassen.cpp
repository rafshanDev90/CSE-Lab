#include <iostream>
using namespace std;

void addMatrix(int A[2][2], int B[2][2], int C[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrix(int A[2][2], int B[2][2], int C[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void strassenMultiply(int A[2][2], int B[2][2], int C[2][2]) {
    int P1, P2, P3, P4, P5, P6, P7;

    P1 = A[0][0] * (B[0][1] - B[1][1]);
    P2 = (A[0][0] + A[0][1]) * B[1][1];
    P3 = (A[1][0] + A[1][1]) * B[0][0];
    P4 = A[1][1] * (B[1][0] - B[0][0]);
    P5 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    P6 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);
    P7 = (A[0][0] - A[1][0]) * (B[0][0] + B[0][1]);

    C[0][0] = P5 + P4 - P2 + P6;
    C[0][1] = P1 + P2;
    C[1][0] = P3 + P4;
    C[1][1] = P1 + P5 - P3 - P7;
}

int main() {
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int C[2][2];

    strassenMultiply(A, B, C);

    cout << "Strassen's Algorithm Multiplication Result:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
