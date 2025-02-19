class Solution {
public:
    void getAllCombinationSum(int index, vector<int> &candidates, int target, vector<int> &tempRes, vector<vector<int>> &finalRes) {
        // Base Case
        if(target == 0) {
            finalRes.push_back(tempRes);
            return;
        }

        if(index >= candidates.size() || target < 0) return;

        // Recursive Case (take and not take)
        tempRes.push_back(candidates[index]);
        getAllCombinationSum(index, candidates, target - candidates[index], tempRes, finalRes);
        tempRes.pop_back();
        getAllCombinationSum(index + 1, candidates, target, tempRes, finalRes);
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> finalRes;
        vector<int> tempRes;
        getAllCombinationSum(0, candidates, target, tempRes, finalRes);
        return finalRes;
    }
};