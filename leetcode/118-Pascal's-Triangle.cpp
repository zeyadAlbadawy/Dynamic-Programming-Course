class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp;
        dp.push_back({1});
        vector<int> newRes;

        for(int i = 1; i < numRows; i++) {
            newRes.push_back(1);
            for(int j = 0; j < i; j++) {
                if(newRes.size() == i)
                   newRes.push_back(1);
                else {
                    newRes.push_back(dp[i - 1][j] + dp[i - 1][j + 1]);
                }
            }
            dp.push_back(newRes);
            newRes.clear();
        }
        return dp;
    }
};