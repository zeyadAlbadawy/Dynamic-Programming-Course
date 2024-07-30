class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp;
        dp.push_back({1});
        vector<int> tempRes;
        for(int i = 1; i <= rowIndex; i++) {
            tempRes.push_back(1);
            for(int j = 0; j < i; j++) {
                if(tempRes.size() == i)
                  tempRes.push_back(1);
                else 
                 tempRes.push_back(dp[i - 1][j] + dp[i - 1][j + 1]);
            }
            dp.push_back(tempRes);
            tempRes.clear();
        }
        return dp[rowIndex];
    }
};