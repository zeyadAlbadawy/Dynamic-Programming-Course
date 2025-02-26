/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> finalRes;
        if(!root) return finalRes;
        queue<TreeNode *> qu;
        qu.push(root);
        while(!qu.empty()) {
            int size = qu.size();
            if(size >= 1) finalRes.push_back(qu.back()->val);
            while(size--) {
                TreeNode *front = qu.front();
                qu.pop();
                if(front->left) qu.push(front->left);
                if(front->right) qu.push(front->right);
            }
        }
        return finalRes;
    }
};