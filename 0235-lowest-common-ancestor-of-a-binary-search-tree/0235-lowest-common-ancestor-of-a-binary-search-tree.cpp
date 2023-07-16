/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool TreeHasP(TreeNode* root, TreeNode* p){
        if(root == nullptr){
            return false;
        }
        if(root == p){
            return true;
        }
        return TreeHasP(root->left, p) || TreeHasP(root->right, p);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr){
            return root;
        }
        if (root == p && (TreeHasP(root->left, q) || TreeHasP(root->right, q))){
            return root;
        }
        if (root == q && (TreeHasP(root->left, p) || TreeHasP(root->right, p))){
            return root;
        }
        if(TreeHasP(root->left, p) && TreeHasP(root->right, q)){
            return root;
        }
        if(TreeHasP(root->right, p) && TreeHasP(root->left, q)){
            return root;
        }
        TreeNode* LCA = lowestCommonAncestor(root->left, p , q);
        if(LCA == nullptr){
            LCA = lowestCommonAncestor(root->right, p , q);
        }
        return LCA;
    }
};