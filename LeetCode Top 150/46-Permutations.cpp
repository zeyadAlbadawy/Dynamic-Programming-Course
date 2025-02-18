class Solution {
public:
    void getPermute(vector<int> &nums, vector<int> &tempRes, vector<vector<int>> &finalRes, vector<bool> &used) {
        if(tempRes.size() == nums.size()) {
            finalRes.push_back(tempRes);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(used[i]) continue;
            used[i] = true;
            tempRes.push_back(nums[i]);
            getPermute(nums, tempRes, finalRes, used);
            tempRes.pop_back();
            used[i] = false;
        }
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> finalRes;
        vector<int> tempRes;
        vector<bool> used(nums.size(), false);
        getPermute(nums, tempRes, finalRes, used);
        return finalRes;
    }
};