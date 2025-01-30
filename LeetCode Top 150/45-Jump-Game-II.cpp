class Solution {
public:
    int getTheMinJump(int itr, vector<int> &nums, vector<int> &dp) {
        if(itr >= nums.size() - 1)
           return 0;
        if(dp[itr] != -1)
           return dp[itr];

        int minJump = 1e9;
        for(int i = 1; i <= nums[itr]; i++) 
            minJump = min(minJump, getTheMinJump(itr + i, nums, dp) + 1);
        return dp[itr] = minJump;
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        return getTheMinJump(0, nums, dp);
    }
};