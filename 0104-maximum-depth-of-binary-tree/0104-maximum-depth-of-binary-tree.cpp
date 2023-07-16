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
    int rec(TreeNode* root, int height){
       if (root != nullptr){
           height += 1;
           return max(rec(root->left, height), rec(root->right,height));
       } 
       return height;
    }
    int maxDepth(TreeNode* root) {
        return rec(root, 0);
    }
};