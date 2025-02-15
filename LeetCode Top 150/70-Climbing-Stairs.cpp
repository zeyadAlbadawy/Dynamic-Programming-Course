class Solution {
public:
    int getTheNoOfWays(vector<int> &dp, int n) {
        if(n == 0) return 1;
        if(n < 0) return 0;

        if(dp[n] != -1)
           return dp[n];
        
        return dp[n] = getTheNoOfWays(dp, n - 1 ) + getTheNoOfWays(dp, n - 2);
    }

    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return getTheNoOfWays(dp, n);
    }
};