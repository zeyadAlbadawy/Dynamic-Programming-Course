class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mp;

        for(int i = 0; i < s.size(); i++) 
           mp[s[i]]++;
        
        for(int i = 0; i < t.size(); i++) 
            mp[t[i]]--;
        
        for(auto &elm :mp)
          if(elm.second != 0) return false;
        return true;
    }
};