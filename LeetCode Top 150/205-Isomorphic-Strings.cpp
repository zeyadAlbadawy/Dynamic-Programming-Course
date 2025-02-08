class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> mp;
        int i = 0;
        while(i < s.size()) {
            if(mp.find(s[i]) != mp.end()) {
                if(mp[s[i]] != t[i])
                   return false;
            } else 
               mp[s[i]] = t[i];
            i++;
        }

        mp.clear();
        i = 0;
        
        while(i < s.size()) {
            if(mp.find(t[i]) != mp.end()) {
                if(mp[t[i]] != s[i])
                   return false;
            } else 
               mp[t[i]] = s[i];
            i++;
        }
        return true;
    }
};