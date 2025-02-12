class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> finalRes;
        int start = 0, end = 0;
        for(int i = 0; i < nums.size(); ) {
            start = end = i;
            while(end + 1 < nums.size() && nums[end + 1] == nums[end] + 1) end++;
            if(end == start) finalRes.push_back(to_string(nums[end]));
            else finalRes.push_back(to_string(nums[start]) + \->\ + to_string(nums[end]));
            i = end + 1;
        }
        return finalRes;
    }
};