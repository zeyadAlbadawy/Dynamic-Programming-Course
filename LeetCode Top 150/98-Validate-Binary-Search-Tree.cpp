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
    bool isValidBST(TreeNode* root, long minVal = LONG_MIN, long maxVal = LONG_MAX) {
        // Base Case
        if(!root) return true;
        if(minVal >= root->val || maxVal <= root->val) return false;
        // Recursive Case
        bool left = isValidBST(root->left, minVal, root->val);
        bool right = isValidBST(root->right, root->val, maxVal);
        return left && right;
    }
};