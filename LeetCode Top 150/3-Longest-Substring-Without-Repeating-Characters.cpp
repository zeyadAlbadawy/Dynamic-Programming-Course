class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        unordered_map<char, int> mp;
        int maxLength = INT_MIN;
        int i = 0, j = 0;
        while(i < s.size() && j < s.size()) {
            if(mp.find(s[j]) != mp.end()) {
                // It exists in the current window
                int lastOcur = mp[s[j]];
                for(int k = i; k <= lastOcur; k++) 
                   mp.erase(s[k]);
                i = lastOcur + 1;
                mp[s[j]] = j;


            } else 
                // it does not exist in the current window.
                mp[s[j]] = j;
            
            maxLength = max(maxLength, j - i  + 1);
            j++;
        }
        return maxLength;
    }
};