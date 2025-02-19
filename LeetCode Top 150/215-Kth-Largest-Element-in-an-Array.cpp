class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Heap to store the lowest element first then the largest ones
        priority_queue<int> pq;
        for(auto &elm : nums) pq.push(elm);
        while(!pq.empty()) {
            if(k == 1) return pq.top();
            k--;
            pq.pop();
        }
        return -1;
    }
};