class Solution {
public:
     int maxLength = INT_MIN;
    string maxStr = \\;
    string longestPalindrome(string s) {
        // Iterate All Over The String And get the max Length Of Odd Substrings
        int rightPtr = 0, leftPtr = 0;
        int tempLength = 0;
        for(int i = 0; i < s.size(); i++ ) {
            rightPtr = leftPtr = i;
            tempLength = 0;
            while (rightPtr < s.size() && leftPtr >= 0 && s[rightPtr] == s[leftPtr]) {
                tempLength = rightPtr - leftPtr + 1;
                if(tempLength > maxLength) {
                    maxStr = s.substr(leftPtr , rightPtr - leftPtr + 1);
                    maxLength = tempLength;
                }
                rightPtr++;
                leftPtr--;
            }
            // Deal With Even Substring
            leftPtr = i;
            rightPtr = i + 1;
            while (leftPtr >=0  && rightPtr < s.size() && s[leftPtr] == s[rightPtr]) {
                tempLength = rightPtr - leftPtr + 1;
                if(tempLength > maxLength) {
                    maxStr = s.substr(leftPtr, rightPtr - leftPtr + 1);
                    maxLength = tempLength;
                }
                rightPtr++;
                leftPtr--;
            }
        }
        return maxStr;
    }
};