const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        
        for(int i = 2; i < nums.size(); i++) 
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        return dp[nums.size() - 1];
    }
};