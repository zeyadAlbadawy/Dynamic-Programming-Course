class Solution {
public:
    bool canReach(int itr, vector<int> &nums, vector<int> &dp) {
        if(itr >= nums.size() - 1)
           return true;

        if(dp[itr] != -1)
          return dp[itr];
        
        for(int i = 1; i <= nums[itr]; i++) {
            if(canReach(itr + i, nums, dp))
               return dp[itr] = true;
        }
        
        return dp[itr] = false;
    }
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return canReach(0, nums, dp);
    }
};