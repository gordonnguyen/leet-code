#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        char island = 1;
        char water = 0;
        int count = 0;

        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[row].size(); col++) {
                if (grid[row][col] == island) {
                    if (((row-1 < 0) || (grid[row-1][col] != island)) 
                        && (((row+1 >= grid.size()) || (grid[row+1][col] != island)))
                        && (((col-1 < 0) || grid[row][col-1] != island)) 
                        && (((col+1 >= grid[row].size()) || grid[row][col+1] != island))) {
                            count++;
                    }
                }
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> grid = {
        {0, 1, 1, 1, 0},
        {1, 1, 0, 1, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };
    //cout << grid[5][5] << "test";
    cout << sol.numIslands(grid) << endl;
}