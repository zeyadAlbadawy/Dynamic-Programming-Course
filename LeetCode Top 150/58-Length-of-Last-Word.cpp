class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream stream(s);
        vector<string> words;
        string word;
        while (stream >> word) {
            if(word == \ \ || word[0] == ' ' && word.size() > 1)
               continue;    
            words.push_back(word); 
        }
        return words.empty() ? 0 : words[words.size() - 1].size();

    }
};