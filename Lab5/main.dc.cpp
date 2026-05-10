#include <iostream>
using namespace std;

void addMatrix(int A[2][2], int B[2][2], int C[2][2], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrix(int A[2][2], int B[2][2], int C[2][2], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void divideAndConquerMultiply(int A[2][2], int B[2][2], int C[2][2], int size) {
    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int half = size / 2;

    int A11[2][2], A12[2][2], A21[2][2], A22[2][2];
    int B11[2][2], B12[2][2], B21[2][2], B22[2][2];
    int C11[2][2], C12[2][2], C21[2][2], C22[2][2];
    int temp1[2][2], temp2[2][2];

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];
            A22[i][j] = A[i + half][j + half];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];
            B22[i][j] = B[i + half][j + half];
        }
    }

    divideAndConquerMultiply(A11, B11, temp1, half);
    divideAndConquerMultiply(A12, B21, temp2, half);
    addMatrix(temp1, temp2, C11, half);

    divideAndConquerMultiply(A11, B12, temp1, half);
    divideAndConquerMultiply(A12, B22, temp2, half);
    addMatrix(temp1, temp2, C12, half);

    divideAndConquerMultiply(A21, B11, temp1, half);
    divideAndConquerMultiply(A22, B21, temp2, half);
    addMatrix(temp1, temp2, C21, half);

    divideAndConquerMultiply(A21, B12, temp1, half);
    divideAndConquerMultiply(A22, B22, temp2, half);
    addMatrix(temp1, temp2, C22, half);

    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            C[i][j] = C11[i][j];
            C[i][j + half] = C12[i][j];
            C[i + half][j] = C21[i][j];
            C[i + half][j + half] = C22[i][j];
        }
    }
}

int main() {
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int C[2][2];

    divideAndConquerMultiply(A, B, C, 2);

    cout << "Divide and Conquer Multiplication Result:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}