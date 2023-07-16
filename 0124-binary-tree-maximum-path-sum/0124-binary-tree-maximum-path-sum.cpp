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
    int maxx;
    int MPS(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = max(MPS(root->left), 0);
        int right = max(MPS(root->right), 0);
        int combined = root->val + left + right;
        maxx = max(maxx, combined);        
        return root->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        maxx = root->val;
        MPS(root);
        return maxx;
    }
};