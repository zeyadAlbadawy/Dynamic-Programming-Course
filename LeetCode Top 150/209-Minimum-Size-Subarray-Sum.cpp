class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
       int i = 0, j = 0, cs = 0;
       int finalRes = 1e9;
       while(i < nums.size() && j < nums.size()) {
          cs += nums[j++];
          if(cs >= target) {
            while(cs >= target) {
                finalRes = min(finalRes, j - i);
                cs -= nums[i++];
            }
          }
       } 
       return finalRes >= 1e9 ? 0 : finalRes;
    }
};