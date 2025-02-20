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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode *> qu;
        qu.push(root);
        int size = qu.size(), cnt = 0;
        double avgSum = 0;
        vector<double> finalRes;
        TreeNode *top = nullptr;
        while(!qu.empty()) {
            avgSum = 0, cnt = 0;
            size = qu.size();
            while(size--) {
                top = qu.front();
                cnt++;
                qu.pop();
                if(top->left) qu.push(top->left);
                if(top->right) qu.push(top->right);
                avgSum += top->val;
            }
            finalRes.push_back(avgSum / cnt);
        }
        return finalRes;
    }
};