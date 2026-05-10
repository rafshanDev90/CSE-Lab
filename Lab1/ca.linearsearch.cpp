#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int linear_search(int arr[], int n, int x){
    for (int i=0; i<n ; i++){
        if (arr[i]== x){
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[]= {1,3,4,5,6};
    int n =5;
    int x=4;

    int result = linear_search(arr, n, x) ;
    cout << "The target value " << x << " is found at index " << result << endl;

    return 0;
}