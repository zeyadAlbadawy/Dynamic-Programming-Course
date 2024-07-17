class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        string finalRes = "";
        int leftPtr = 0, rightPtr = 0;

        for(int i = 0; i < s.size(); i++) {
            leftPtr = rightPtr = i;

            // Odd Substring
            while(leftPtr >= 0 && rightPtr < s.size() && s[leftPtr]== s[rightPtr]) {
                if(rightPtr - leftPtr + 1 > finalRes.size()) 
                   finalRes = s.substr(leftPtr, rightPtr - leftPtr + 1);
                leftPtr--;
                rightPtr++;
            }

            // Even Substring
            rightPtr = i + 1;
            leftPtr = i;
            while(leftPtr >= 0 && rightPtr < s.size() && s[leftPtr] == s[rightPtr]) {
                if(rightPtr - leftPtr + 1 > finalRes.size()) 
                   finalRes = s.substr(leftPtr, rightPtr - leftPtr + 1);
                leftPtr--;
                rightPtr++;
            }
        }

        return finalRes;
    }
};