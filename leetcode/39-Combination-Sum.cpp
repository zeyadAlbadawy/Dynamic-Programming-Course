class Solution {
public:
    void getCombinationSum(vector<int> &candidates, int target, vector<vector<int>> &finalRes, vector<int> &tempRes, int x) {
        // Base Case
            if(target == 0) {
            finalRes.push_back(tempRes);
            return;
        }

        if(x == candidates.size() || target < 0)
             return;

        // Recursive Case Either Execlude it or include it infite numbers
        tempRes.push_back(candidates[x]);
        getCombinationSum(candidates, target - candidates[x], finalRes, tempRes, x);
        tempRes.pop_back();
        getCombinationSum(candidates, target, finalRes, tempRes, x + 1);

        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> finalRes;
        vector<int> tempRes;
        getCombinationSum(candidates, target, finalRes, tempRes, 0);
        return finalRes;
    }
};
