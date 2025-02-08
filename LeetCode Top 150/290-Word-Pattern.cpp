class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> res;
        map<char, string> mp;
        int i = 0, j = 0;
        while(i < s.size()) {
            if(s[i] != ' ') {
                i++;
                continue;
            } else {
                res.push_back(s.substr(j, i - j));
                j = i + 1;
                i++;
            }
        }
        res.push_back(s.substr(j, i - j));

        if(pattern.size() != res.size()) return false;
        i = 0;
         while(i < pattern.size()) {
            if(mp.find(pattern[i]) != mp.end()) {
                if(mp[pattern[i]] != res[i])
                   return false;
            } else 
               mp[pattern[i]] = res[i];
            i++;
        }
        map<string, char> mp1;
        i = 0;
        
        while(i < res.size()) {
            if(mp1.find(res[i]) != mp1.end()) {
                if(mp1[res[i]] != pattern[i])
                   return false;
            } else 
               mp1[res[i]] = pattern[i];
            i++;
        }

        return true;
    }
};