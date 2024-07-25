class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int j = 0, maxElm = INT_MIN;
        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j <= i; j++) {
                // If j rearched i
                if(j == i)
                    break;
                // Other Wise
                if(nums[i] > nums[j]) 
                    dp[i] = max(dp[j] + 1, dp[i]);
            }
        }

        // Get The Max Subseq
        for(int i = 0; i < nums.size(); i++) {
            if(dp[i] > maxElm) 
              maxElm = dp[i];
        }
        return maxElm;   
    }
};