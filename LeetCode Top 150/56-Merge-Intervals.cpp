class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1) return intervals; 
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> finalRes;
        vector<int> v1, v2;
        finalRes.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++) {
            v1 = finalRes.back();
            v2 = intervals[i];
            if(v2[0] >= v1[0] && v2[0] <= v1[1]) {
               finalRes.pop_back();
               finalRes.push_back({min(v1[0], v2[0]), max(v1[1], v2[1])});
            }
            else finalRes.push_back(v2);
        }

        return finalRes;
    }
};