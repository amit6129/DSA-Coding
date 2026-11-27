#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalSurplus = 0;
        int currentTank = 0;
        int startStation = 0;

        for (int i = 0; i < static_cast<int>(gas.size()); ++i) {
            int diff = gas[i] - cost[i];
            totalSurplus += diff;
            currentTank += diff;

            if (currentTank < 0) {
                startStation = i + 1;
                currentTank = 0;
            }
        }

        return (totalSurplus >= 0) ? startStation : -1;
    }
};
