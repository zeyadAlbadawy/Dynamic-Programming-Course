class Solution {
public:
    int DFS(int i, string s, vector<int> &dp) {
        // Base Cases
        if(i == s.size()) 
          return 1;
        if(s[i] == '0' )
          return 0;
        if(dp[i] != -1)
          return dp[i];
        
        int res = DFS(i + 1, s, dp);
        if((i + 1 < s.size()) && (s[i] == '1' || (s[i] == '2' && s[i + 1] >= '0' && s[i + 1] <= '6')))
          res += DFS(i + 2, s, dp);
        dp[i] = res;
        return res;
    }

    int numDecodings(string s) {
        if(s.empty()) return 0;
        vector<int> dp(s.size(), -1);
        return DFS(0, s, dp);
    }
};