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
    vector<int> res;
    
    void Traversal(TreeNode* root){
        if(root == nullptr) return;
        Traversal(root->left);
        res.push_back(root->val);
        Traversal(root->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        Traversal(root);
        return res;
    }
};