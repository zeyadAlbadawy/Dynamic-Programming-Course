const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Bottom Up Approach
        if(amount < 1) 
           return 0;
        
        vector<int> dp(amount + 1);
        for(int i = 1; i <= amount ; i++) {
            dp[i] = INT_MAX;
            for(auto coin : coins) {
                if(coin <= i && dp[i - coin] != INT_MAX) 
                   dp[i] = min(dp[i - coin] + 1, dp[i]); 
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};