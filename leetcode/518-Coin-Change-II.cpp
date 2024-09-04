class Solution {
public:
    int finalRes = 0;
    int getTheNumOfCoins(vector<int> &coins,int amount,vector<vector<int>> &dp, int itr) {
        if(amount == 0) {
            return finalRes + 1;
        }

        if(itr >= coins.size() || amount < 0)
             return 0;

        if(dp[itr][amount] != -1)
             return dp[itr][amount];

        // Inclde
        int inc = getTheNumOfCoins(coins, amount - coins[itr], dp, itr);
        // Exclude
        int exclude = getTheNumOfCoins(coins, amount, dp, itr + 1);
        return dp[itr][amount] = inc + exclude;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int> (amount + 1, -1));
        return getTheNumOfCoins(coins, amount,dp, 0);
    }
};