class Solution {
public:
    string simplifyPath(string path) {
        vector<string> tokens;
        istringstream iss(path);
        string token;

        while(getline(iss, token, '/')) {
            if(token == \.\ || token == \\)
               continue;
            tokens.push_back(token);
            cout << token << endl;
        }

        // Handle the .. which means one step back for each
        vector<string> stack;

        // If it is Relative path, mention that by push empty string 
        if(path[0] == '/')
            stack.push_back(\\);

        for(auto token : tokens) {
            if(token == \..\) {
                // check if the stack is empty then it must be pushed OR the
               // Prev element is .. then it can't be removed untill now
                if(!stack.size() || stack[stack.size() - 1] == \..\)
                   stack.push_back(token);
                else if(stack[stack.size() - 1] != \\) 
                   stack.pop_back();
            } else 
              stack.push_back(token);
        }

        // Combine all the elements in the stack and give the finalRes
        if(stack.size() == 0 && stack[stack.size() - 1] == \\)
           return \/\;
        
        path.clear();
        for(int i = 0; i < stack.size(); i++)
            path += stack[i] + '/';
        if(path.size() != 1)
           path.pop_back();
        return path;
    }
};