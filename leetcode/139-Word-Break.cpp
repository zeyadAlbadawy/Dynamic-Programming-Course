class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()  + 1, false);
        dp[s.size()] = true;
        int j  = s.size() - 1;
        string temp = "";
        while(j >= 0) {
            temp = s.substr(j , s.size() - j );
            for(int y = 0; y < wordDict.size(); y++) {
                if((temp.size() >= wordDict[y].size()) && (temp.substr(0, wordDict[y].size()) == wordDict[y])) {
                    dp[j] = dp[j + wordDict[y].size()];
                    if(dp[j]) break;
                }
            }
            j--;
        }
        return dp[0];
    }
};