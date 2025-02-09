class Solution {
public:
    bool isHappy(int n) {
    unordered_map<int, int> mp;
    int sum = 0;
    while(true) {
        while(n != 0) {
            sum += pow(n % 10, 2);
            n /= 10;
        }

        if(sum == 1) return true;
        if(mp.count(sum)) return false;
        mp[sum]++;
        n = sum;
        sum = 0;
       } 
       return true;
    }
};