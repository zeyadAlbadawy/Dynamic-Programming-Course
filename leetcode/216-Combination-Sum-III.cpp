class Solution {
public:
    void getAllCombinationsWithK(vector<int>&nums, vector<int> &tempRes, vector<vector<int>> &finalRes, int &k,int target ,int itr) {
        if(target == 0) {
            if(tempRes.size() == k)
                finalRes.push_back(tempRes);
            return;
        }
        if(itr >= nums.size() || target < 0)
            return;

        tempRes.push_back(nums[itr]);
        getAllCombinationsWithK(nums, tempRes, finalRes, k , target - nums[itr], itr + 1);
        tempRes.pop_back();
        getAllCombinationsWithK(nums, tempRes, finalRes, k, target, itr + 1);
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        for(int i = 1; i <= 9; i++)
            nums.push_back(i);
        vector<vector<int>>finalRes;
        vector<int>tempRes;
        getAllCombinationsWithK(nums, tempRes, finalRes,k , n, 0);
        return finalRes;
    }
};