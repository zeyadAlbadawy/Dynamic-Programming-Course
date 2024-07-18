class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        int first = 0, second = 1, temp = 0;
        for(int i = 2; i <= n; i++) {
            temp = second;
            second += first;
            first = temp;
        }
        return second;
    }
};