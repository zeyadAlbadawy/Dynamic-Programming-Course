class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int itr1 = 0, itr2 = nums.size() - 1;
        int totalSum = nums[itr1] + nums[itr2];
        while(itr1 < itr2) {
            cout << itr1 << \ \ << itr2 << endl;
            if(totalSum > target) {
                totalSum -= nums[itr2];
                itr2--;
                totalSum += nums[itr2];
            } else if (totalSum < target) {
                totalSum -= nums[itr1];
                itr1++;
                totalSum += nums[itr1];
            } else 
               return {itr1 + 1, itr2 + 1};
        }
        return {-1, -1};
    }
};