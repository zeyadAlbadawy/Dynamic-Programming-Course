class Solution {
public:
    int getTheMaxProfit(vector<int> &prices, vector<vector<int>> &dp, int itr, int buy) {
        if(itr == prices.size())
            return 0;
        if(dp[itr][buy] != -1)
            return dp[itr][buy];

        int maxProfit = 0;
        if(buy)
            maxProfit = max((-prices[itr] + getTheMaxProfit(prices, dp, itr + 1, 0)),( 0  + getTheMaxProfit(prices, dp,itr + 1, 1)));
         else
            maxProfit = max(prices[itr] + getTheMaxProfit(prices, dp , itr + 1, 1), 0+  getTheMaxProfit(prices, dp, itr + 1, 0));
        return dp[itr][buy] = maxProfit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return getTheMaxProfit(prices, dp,  0, 1);

   }
};