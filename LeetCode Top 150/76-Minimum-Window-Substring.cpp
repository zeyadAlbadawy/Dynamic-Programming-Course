class Solution {
    public:
        string minWindow(string s, string t) {
            map<char, int> mpP;
            map<char, int> mpS;
            string finalStr;

           \t// initialize the frequency of the pattern
            for (int i = 0; i < t.size(); i++)
                mpP[t[i]]++;

           \t// Check upon the string
            int cnt = 0, start = 0, minSize = 1e9, finalStart = -1;
            for (int i = 0; i < s.size(); i++) {
                mpS[s[i]]++;

               \t// count how many characters have been matched
                if (mpP[s[i]] != 0 && mpS[s[i]] <= mpP[s[i]])
                    cnt++;

                if (cnt == t.size()) {
                   \t// Start Shrinking The Window
                   \t// 1) The Current window start is not included in the pattern
                   \t// 2) It Has Higher Frequency than required
                    while (mpP[s[start]] == 0 || mpS[s[start]] > mpP[s[start]]) {
                        mpS[s[start]]--;
                        start++;
                    }
                   \t// You Reached the suitable window length after shrinking
                    if (i - start + 1 < minSize) {
                        minSize = min(minSize, i - start + 1);
                        finalStart = start;
                    }
                }
            }
            return finalStart == -1 ? \\ : s.substr(finalStart, minSize);
        }
};