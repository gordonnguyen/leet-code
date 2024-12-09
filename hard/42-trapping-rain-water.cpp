#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        //check empty space from distance i to j with values of i = j
        int current_row = 1, max_row = 1;
        int first_index = -1;
        int total_trap = 0;

        cout << "init first index: " << first_index << endl;

        for (current_row; current_row <= max_row; current_row++) {
            cout << "row" << current_row << endl;
            for (int i = 0; i < height.size(); i++) {
                cout << "i" << i;
                if ((height[i] >= current_row)) {
                    // Set max height to the highest value in the array
                    if (height[i] > max_row ) {
                        max_row = height[i];
                        cout << "max height " << max_row << endl;
                    }
                    // Check if index a is set
                    if ((first_index == -1)) {
                        first_index = i;
                    }
                    else {
                        // Caclculate the space between index 1 and 2
                        cout << "distance " << i << "-" << first_index << "=" << i-first_index-1 << endl;
                        cout << "first index in loop: " << first_index << endl;
                        total_trap += i - first_index -1;
                        cout << endl << "total trap: " << total_trap << endl;
                        first_index = i;
                        cout << "===============" << endl;
                    }
                }
            }
            // Unset first_index for next row
            first_index = -1;
        }
        return total_trap;
    }
};

int main() {
    vector<int> v1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> v2 = {4,2,0,3,2,5};
    Solution sol;
    cout << sol.trap(v2) << endl;
}