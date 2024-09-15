class Solution {
public:
    int getTheMinPath(int itr, vector<int> &nums) {
        int maxJump = 0, minPath = 0, maxItr = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
           if(i <= maxJump) {
               maxItr = max(maxItr, i + nums[i]);
           } else  {
               i--;
               maxJump = maxItr;
               minPath += 1;
               maxItr = INT_MIN;
           }
        }
        return minPath;
    }
    int jump(vector<int>& nums) {
        return getTheMinPath(0, nums);
    }
};