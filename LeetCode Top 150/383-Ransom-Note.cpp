class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<int, int> mp1;
        map<int, int> mp2;

        for(int i = 0; i < magazine.size(); i++)
           mp1[magazine[i]]++;
        for(int i = 0; i < ransomNote.size(); i++)
           mp2[ransomNote[i]]++;

        for(auto &elm : mp2) {
            if(mp1[elm.first] < mp2[elm.first])
               return false;
        }
        return true;
    }
};