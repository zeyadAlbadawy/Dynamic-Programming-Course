class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0, right = 1;
        int finalRes = 0;

        while(right < prices.size()) {
            if(prices[right] < prices[left])
               left = right;
            else 
              finalRes = max(prices[right] - prices[left], finalRes);
            right++;
        }
        return finalRes;
    }
};