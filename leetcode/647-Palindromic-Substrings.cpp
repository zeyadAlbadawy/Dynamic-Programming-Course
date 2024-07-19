class Solution {
public:
    int countSubstrings(string s) {
        if(s.size() <= 1) return s.size();
        int cnt = 0, left = 0, right = 0;

        for(int i = 0; i < s.size(); i++) {
            // Odd Substrings
            left = right = i;
            while(right < s.size() && left >= 0 && s[right] == s[left] ) {
                cnt++;
                left--;
                right++;
            }

            // Even Substrings
            left = i, right = i + 1;
            while(right < s.size() && left >= 0 && s[right] == s[left] ) {
                cnt++;
                left--;
                right++;
            }
            
        }
        return cnt;
    }
};