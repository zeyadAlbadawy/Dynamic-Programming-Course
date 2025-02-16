class Solution {
public:
    string reverseWords(string s) {
        istringstream stream(s);
        vector<string> res;
        string word, str;
        while (stream >> word)
            res.push_back(word);
                
        for(int i = res.size() - 1; i >= 0; i--)
            str += res[i] + \ \;
        
        str.pop_back();
        return str;

    }
};