class Solution {
public:
    int getTheMaxProfit(int itr, int buy,vector<vector<int>> &dp, vector<int> &prices) {
        int maxProfit = 0;
        if(itr >= prices.size()) 
          return 0;
        if(dp[buy][itr] != -1)
           return dp[buy][itr];

        if(buy)
          maxProfit = max((-prices[itr] + getTheMaxProfit(itr + 1, 0, dp, prices)), (0  + getTheMaxProfit(itr + 1, 1, dp, prices)));
        else
          maxProfit = max((+prices[itr] + getTheMaxProfit(itr + 2, 1, dp, prices)), (0 + getTheMaxProfit(itr + 1, 0, dp, prices)));
        return dp[buy][itr] = maxProfit;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int> (prices.size() + 2, 0));
        // return getTheMaxProfit(0, 1,dp, prices);
        // Perform Tabluation
        for(int itr = prices.size() - 1; itr >= 0; itr--) {
            for(int buy = 0; buy < 2; buy++) {
                int maxProfit = 0;
                if(buy)
                   maxProfit = max((-prices[itr] + dp[0][itr + 1]), (0 + dp[1][itr + 1]));
                else 
                 maxProfit = max((+prices[itr] + dp[1][itr + 2] ), (0 + dp[0][itr + 1]));
                dp[buy][itr] = maxProfit;
            }
        }
        return dp[1][0];
    }
};