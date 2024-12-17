/*
1094. Car Pooling

There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.

Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.

*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // List all locations with passengers number
        // Find max number of passengers in the list
        // If max_psg < capacity then true
        // else false
        int max_psg = 0; 
        vector<int> loc;

        // List passengers with each location
        for (vector<int> trip: trips) {
            // Resize vector if larger
            if (trip[2]+1 > loc.size()) {
                loc.resize(trip[2] + 1, 0);
            }
            // Iterate each trip [passengers, from, to] to the loc list
            for (int i=trip[1]; i <= trip[2]-1; i++) {
                loc[i] += trip[0];
                if (loc[i] > max_psg) {
                    max_psg = loc[i];
                    cout << "max psg: " << max_psg << " | " << i << endl;
                }
            }
        }

        
        // Test Print
        cout << loc.size() << " | ";
        for (auto const& value: loc) {
            cout << value << " ";
        }
        cout << endl;

        if (max_psg <= capacity) {
            return true;
        }
        return false;
    }
};

int main() {
    // Test case
    Solution sol;
    vector<vector<int>> sample_trip = {{2,1,5},{3,5,7}};
    cout << sol.carPooling(sample_trip, 3) << endl;
};