class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n = citations.size();
        int left = 0, right = n - 1, mid = 0;
        
        while(left <= right) {
            mid = (left + right) / 2;
            if(n - mid > citations[mid]) 
                left = mid + 1;
            else right = mid - 1;
        }
        return n - left;
    }
};