#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string  str = to_string(x);
        for (int i=0; i<=((str.length()-1)/2); i++) {
            cout << str[i] << " " << str[str.length()-1-i] << endl;
            if (str[i]!=str[str.length()-1-i]) {
                cout << "Str ended at " << i << endl;
                return false;
            }
        }
        return true;
    }
};

int main() {
    int x = 121;
    int x2 = -121;
    int x3 = 2412;
    string str = to_string(x2);
    cout << str << endl;
    Solution sol;
    cout << sol.isPalindrome(x3) << endl; 
};