const static auto _ = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
          return nums[0];
        int robF = nums[0], robS = max(nums[0], nums[1]), temp = 0;

        for(int i = 2; i < nums.size(); i++) {
            temp = max(robF + nums[i], robS);
            robF = robS;
            robS = temp;
        }
        return robS;
    }
};