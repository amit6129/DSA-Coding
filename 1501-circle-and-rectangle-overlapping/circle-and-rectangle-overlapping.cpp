#include <algorithm>

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        // Find the closest x-coordinate on the rectangle to the circle's center
        int closestX = std::max(x1, std::min(xCenter, x2));
        
        // Find the closest y-coordinate on the rectangle to the circle's center
        int closestY = std::max(y1, std::min(yCenter, y2));
        
        // Calculate the squared distance between the circle's center and this closest point
        int distanceX = xCenter - closestX;
        int distanceY = yCenter - closestY;
        int squaredDistance = (distanceX * distanceX) + (distanceY * distanceY);
        
        // If the distance is less than or equal to the radius, they overlap
        return squaredDistance <= (radius * radius);
    }
};
