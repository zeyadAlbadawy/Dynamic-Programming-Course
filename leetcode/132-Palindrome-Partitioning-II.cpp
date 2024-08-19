class Solution {
public:

    bool isPalindrome(int i, int j, string &s) {
        while(i <= j) {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int minCount(string &s, int i,  vector<int> &dp) {


        if(i == s.size())
             return 0;
        if(dp[i] != -1)
            return dp[i];
        
        int fullCnt = INT_MAX;
        for(int j = i; j < s.size(); j++) {
            if(isPalindrome(i, j, s)) {
                int tempCnt = 1 + minCount(s ,j + 1, dp);
                fullCnt = min(fullCnt, tempCnt);
            }
        }
        return dp[i] = fullCnt;
    }

    int minCut(string s) {
        vector<string> tempRes;
        string tempS;
        vector<int> dp(s.size() + 1, -1);
        int finalRes = minCount(s, 0, dp);
        return finalRes - 1;
    }
};