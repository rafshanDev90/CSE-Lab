#include <iostream>
using namespace std;

int findMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int arr[] = {12, 34, 5, 67, 23, 89, 45};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    int max = findMax(arr, n);
    cout << "Maximum element: " << max << endl;
    
    return 0;
}
