class Solution {
public:
    void getAllCombinations(int itr, int &k, vector<int> &res, vector<int> &temp, vector<vector<int>> &finalRes) {
        // Base Case
        if(temp.size() == k) {
            finalRes.push_back(temp);
            return;
        }
        if(itr >= res.size()) return;
        // Take The Curr 
        temp.push_back(res[itr]);
        getAllCombinations(itr + 1, k, res, temp, finalRes);
        // Skip the curr
        temp.pop_back();
        getAllCombinations(itr + 1, k, res, temp, finalRes);
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp, res;
        vector<vector<int>> finalRes;
        for(int i = 1; i <= n; i++) res.push_back(i);
        getAllCombinations(0, k, res, temp, finalRes);
        return finalRes;
    }
};