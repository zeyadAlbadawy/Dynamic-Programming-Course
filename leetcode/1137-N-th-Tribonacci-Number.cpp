class Solution {
public:
    int tribonacci(int n) {
        if(n < 2)
          return n;
        int first = 0, second = 1, third = 1, temp = 0;
        for(int i = 3; i <= n ; i++) {
            temp = second;
            second += first;
            first = temp;
            temp = third;
            third += second;
            second = temp;
        }
        return third;
    }
};