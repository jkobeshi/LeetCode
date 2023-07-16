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

    int minSide(TreeNode* root){
        while(root->left != nullptr){
            root = root->left;
        }
        return root->val;
    }

    int maxSide(TreeNode* root){
        while(root->right != nullptr){
            root = root->right;
        }
        return root->val;
    }

    bool isValidBST(TreeNode* root) {
        if(root == nullptr || (root->left == nullptr && root->right == nullptr)) return true;
        if(root->left == nullptr){
            if(root->val >= root->right->val) return false;
            if(root->val >= minSide(root->right)) return false;
        }
        else if(root->right == nullptr){
            if(root->left->val >= root->val) return false;
            if(maxSide(root->left) >= root->val) return false;
        }
        else if(root->left->val >= root->val || root->val >= root->right->val) return false;
        else if(maxSide(root->left) >= root->val || root->val >= minSide(root->right)) return false;
        return isValidBST(root->left) && isValidBST(root->right);
    }
};