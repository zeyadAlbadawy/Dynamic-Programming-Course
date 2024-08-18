class Solution {
    public: 
    int getTheFullCount(string &s, int i, vector<int> &dp) {

       \t// Base Case
        if (i > s.size() || s[i] == '0')
            return 0;

       \t// Where I Should Terminate And Increment The final res
        if (i == s.size())
            return 1;

       \t// For Memoization
        if (dp[i] != -1)
            return dp[i];

       \t// You Have Two Choices
       \t// 1- get only one num at a time
       \t// 2- get Two numbers at a time

        int finalRes = 0;
        finalRes += getTheFullCount(s, i + 1, dp);

        if (i + 1 < s.size() && ((s[i] == '2' && s[i + 1] <= '6') || (s[i] == '1')))
            finalRes += getTheFullCount(s, i + 2, dp);

        dp[i] = finalRes;
        return finalRes;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return  getTheFullCount(s, 0, dp);
    }
};