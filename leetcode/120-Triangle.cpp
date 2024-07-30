class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int height = triangle.size(); 
       vector<vector<int>> dp(height, vector<int>(height, 0));
        dp[height - 1] = triangle[height - 1];
        for(int i = height - 2; i >= 0; i-- ) {
            for(int j = 0; j < triangle[i].size(); j++) {
                dp[i][j] = triangle[i][j] + min(dp[i+1][j] , dp[i + 1][j + 1]);
            }
        }
        return dp[0][0];
    }
};