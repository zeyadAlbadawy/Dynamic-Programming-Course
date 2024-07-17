class Solution {
public:
    int helperFunc(vector<int> &nums, int start, int end) {
        if (end == start) return nums[start]; 
        int robFirst = nums[start], robSecond = max(nums[start], nums[start + 1]), temp = 0;
        // [robF, robS, temp]
        for(int i = start + 2; i <= end; i++) {
            temp = max(robFirst + nums[i], robSecond);
            robFirst = robSecond;
            robSecond = temp;
        }
        return robSecond;
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        return max(helperFunc(nums, 0, nums.size() - 2), helperFunc(nums, 1, nums.size() - 1));
    }
};