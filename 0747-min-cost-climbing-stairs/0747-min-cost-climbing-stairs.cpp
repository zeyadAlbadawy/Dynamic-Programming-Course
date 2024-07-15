int speedUp = [] {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        for(int i = cost.size() - 3; i >= 0; i--) 
          cost[i] += min(cost[i + 1], cost[i + 2]);
        return min(cost[0], cost[1]);
    }
};