class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> finalRes;
        vector<string> tempRes;
        string temp = \\;

        for(int i = 0; i < strs.size(); i++) {
            temp = strs[i];
            sort(temp.begin(), temp.end());
            tempRes.push_back(temp);
        }
        
        map<string, set<int>> mp;
        for(int i = 0; i < tempRes.size(); i++)
            mp[tempRes[i]].insert(i);
        
        tempRes.clear();
        for(auto &elm : mp) {
            tempRes.clear();
            for(auto &itr : elm.second) {
                tempRes.push_back(strs[itr]);
            }
            finalRes.push_back(tempRes);
        } 
        return finalRes;
    }
};