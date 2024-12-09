#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        //check empty space from distance i to j with values of i = j
        bool loop = true;
        int current_height = 1, max_height = 1;
        int first_index = 0;
        int total_trap = 0;
        int j = 0;
        for (j; j < height.size(); j++) {
            if ((height[j] >= current_height) && (first_index = 0)) {
                first_index = j;
                break;
            }
        }
        cout << "init first index: " << first_index << endl;

        // Iterate all indexes in a row
        while (first_index + 1 < height.size()) {
            cout << "first index: " << first_index << endl;

            // Iterate space between 2 "walls"
            for (int i = first_index+1; i < height.size(); i++) {
                cout << "i" << i;
                if ((height[i] >= current_height)) {
                    // Set max height to the highest value in the array
                    if (height[i] > max_height) {
                        max_height = height[i];
                        cout << "max height " << max_height << endl;
                    }
                    // Caclculate the space between index 1 and 2
                    total_trap += i - first_index - 1;
                    cout << endl << "total trap: " << total_trap << endl;
                    first_index = i;
                    cout << "first index in loop: " << first_index << endl;
                    cout << "===============" << endl;
                    break;
                }
            }
        }
        // total_trap += empty_space
        return total_trap;
    }
};

int main() {
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution sol;
    cout << sol.trap(v) << endl;
}