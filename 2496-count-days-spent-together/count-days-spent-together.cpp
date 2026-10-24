#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

class Solution {
private:
    // Days in each month for a non-leap year
    const std::vector<int> daysInMonths = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Helper function to convert "MM-DD" to a 1-based day of the year
    int dateToDayOfYear(const std::string& date) {
        int month = std::stoi(date.substr(0, 2));
        int day = std::stoi(date.substr(3, 2));
        
        // Sum up the days of all previous months
        int dayCount = 0;
        for (int i = 0; i < month - 1; ++i) {
            dayCount += daysInMonths[i];
        }
        
        return dayCount + day;
    }

public:
    int countDaysTogether(std::string arriveAlice, std::string leaveAlice, std::string arriveBob, std::string leaveBob) {
        // Convert all dates to absolute days of the year
        int startAlice = dateToDayOfYear(arriveAlice);
        int endAlice = dateToDayOfYear(leaveAlice);
        int startBob = dateToDayOfYear(arriveBob);
        int endBob = dateToDayOfYear(leaveBob);
        
        // Find the overlapping interval
        int overlapStart = std::max(startAlice, startBob);
        int overlapEnd = std::min(endAlice, endBob);
        
        // Calculate the number of overlapping days
        if (overlapStart <= overlapEnd) {
            return overlapEnd - overlapStart + 1;
        }
        
        return 0;
    }
};
