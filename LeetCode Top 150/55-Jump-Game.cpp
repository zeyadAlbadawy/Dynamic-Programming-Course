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
        // Iterative approach
        int maxReach = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(i > maxReach) return false;
            maxReach = max(maxReach, nums[i] + i);
            if(maxReach >= nums.size() - 1) 
              return true;
        }
        return false;
    }
};