
class Solution {
public:
    bool checkPartitioning(vector<int> &nums, int totalSum, int idx, vector<vector<int>> &res) {
        // Base Case
        if(res[totalSum][idx] != -1)
            return res[totalSum][idx];


        if(idx >= nums.size())
            return (totalSum == 0);

        bool resTemp = false;
        // Include The Current Number
        if(totalSum >=  nums[idx])
            resTemp |= checkPartitioning(nums, totalSum - nums[idx], idx + 1, res);
        // Execlude The Current Number
           resTemp  |= checkPartitioning(nums, totalSum, idx + 1, res);
        return res[totalSum][idx] = resTemp;
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for(auto elm : nums)
            totalSum += elm;
        if(totalSum % 2 != 0)
            return false;
        totalSum /= 2;
        vector<vector<int>> res(totalSum + 1, vector<int>(nums.size() + 1, -1));
        return checkPartitioning(nums, totalSum, 0, res);
    }
};

