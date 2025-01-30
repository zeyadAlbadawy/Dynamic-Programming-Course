class Solution {
public:
    bool isPalindrome(string s) {
        string finalStr = \\;
        for(int i = 0; i < s.size(); i++) {
            if(isalpha(s[i]))
               finalStr += tolower(s[i]);
            else if(isdigit(s[i]))
               finalStr += s[i];
        }
        int start = 0, end = finalStr.size() - 1;
        while(start <= end) {
            if(finalStr[start] != finalStr[end])
               return false;
            start++;
            end--;
        }
        return true;
    }
};