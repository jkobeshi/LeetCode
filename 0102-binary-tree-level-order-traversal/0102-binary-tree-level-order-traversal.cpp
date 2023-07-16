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
    vector<vector<int>> res;
    void levelOrd(TreeNode* root, int height){
        if(root == nullptr) return;
        if(height >= res.size()) res.push_back({root->val});
        else res[height].push_back(root->val);
        if(root->left != nullptr) levelOrd(root->left, height + 1);
        if(root->right != nullptr) levelOrd(root->right, height + 1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        levelOrd(root, 0);
        return res;
    }
};