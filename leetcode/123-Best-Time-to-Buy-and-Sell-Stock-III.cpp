class Solution {
public:
    int getTheMaxProfit(vector<int> &prices, vector<vector<vector<int>>> &dp, int itr, int buy, int noOfTimes) {
        if(itr >= prices.size() || noOfTimes > 2)
            return 0;
        if(dp[itr][buy][noOfTimes] != -1) {
            return dp[itr][buy][noOfTimes];
        }

        int maxProfit = 0;
        if(buy)
            maxProfit = max(-prices[itr] + getTheMaxProfit(prices, dp, itr + 1, 0, noOfTimes + 1),( 0  + getTheMaxProfit(prices, dp,itr + 1, 1, noOfTimes )));
         else
            maxProfit = max(prices[itr] + getTheMaxProfit(prices, dp , itr + 1, 1, noOfTimes  ), 0 +  getTheMaxProfit(prices, dp, itr + 1, 0, noOfTimes));
        return dp[itr][buy][noOfTimes] = maxProfit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        return getTheMaxProfit(prices, dp,  0, 1, 0);

   }
};