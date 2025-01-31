class Solution {
public:
    bool isSubsequence(string s, string t) {
        int itr1 = 0, itr2 = 0;
        while(itr1 < s.size() && itr2 < t.size()) {
            if(s[itr1] == t[itr2]) 
                itr1++;
            itr2++;
        }
        if(itr1 >= s.size())
           return true;
        return false;
    }
};