class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int leftSum = 0;
        int rightSum = 0;
        int maxSum = INT_MIN;

        for(int i = 0; i < nums.size(); i++) {
            leftSum = leftSum < 0 ? 0 : leftSum;
            rightSum = rightSum < 0 ? 0 : rightSum;
            leftSum += nums[i];
            rightSum += nums[nums.size() - 1 - i];
            maxSum = max({maxSum, leftSum, rightSum});
        }
        return maxSum;
    }
};