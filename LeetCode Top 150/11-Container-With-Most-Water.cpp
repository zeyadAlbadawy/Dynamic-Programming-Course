#include <algorithm
class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int leftItr = 0, rightItr = height.size() - 1;
        int maxArea = 0;

        while (leftItr < rightItr) {            
            maxArea = max(maxArea, (rightItr - leftItr) * min(height[leftItr], height[rightItr]));
            if (height[leftItr] < height[rightItr])
                leftItr++;
             else 
                rightItr--;
        }
        return maxArea;
    }
};