#include <iostream>
#include <string>
#include <vector>
using namespace std;

string gradeSchoolMult(string num1, string num2) {
    int n1 = num1.size();
    int n2 = num2.size();
    
    if (n1 == 0 || n2 == 0) {
        return "0";
    }
    
    vector<int> result(n1 + n2, 0);
    
    int i1 = 0, i2 = 0;
    
    for (int i = n1 - 1; i >= 0; i--) {
        int carry = 0;
        int n1_digit = num1[i] - '0';
        
        i2 = 0;
        
        for (int j = n2 - 1; j >= 0; j--) {
            int n2_digit = num2[j] - '0';
            
            int sum = n1_digit * n2_digit + result[i1 + i2] + carry;
            
            carry = sum / 10;
            result[i1 + i2] = sum % 10;
            
            i2++;
        }
        
        if (carry > 0) {
            result[i1 + i2] += carry;
        }
        
        i1++;
    }
    
    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0) {
        i--;
    }
    
    if (i == -1) {
        return "0";
    }
    
    string str = "";
    
    while (i >= 0) {
        str += to_string(result[i--]);
    }
    
    return str;
}

int main() {
    string num1 = "123456789";
    string num2 = "987654321";
    cout << "Number 1: " << num1 << endl;
    cout << "Number 2: " << num2 << endl;
    string product = gradeSchoolMult(num1, num2);
    cout << "Product: " << product << endl;
    return 0;
}
