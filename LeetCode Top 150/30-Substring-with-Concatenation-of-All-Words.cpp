class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> finalRes;
        int finalStart = 0, windowLen = words[0].size();
        if(s.size() <  windowLen * words.size()) return {};
        bool flag = false;
        unordered_map<string, int> mp1, mp2;
        for(auto elm : words)
           mp1[elm]++;
        mp2 = mp1;

            for(int i = 0; i <= s.size() - windowLen * words.size() ; i++) {
                string str = s.substr(i, windowLen * words.size());
                finalStart = i;
                for(int j = 0; j < windowLen * words.size(); j+=windowLen) {
                    string temp = str.substr(j, windowLen);
                    if(mp1.count(temp) == 0) break;
                    else mp1[temp]--;
                }

                bool flag = true;
                for(auto &elm : mp1) 
                    if(elm.second != 0) {
                       flag = false;
                       break;
                    }
                if(flag) finalRes.push_back(finalStart);
                mp1 = mp2;
            }
        return finalRes;
    }
};