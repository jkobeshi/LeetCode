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

    bool bal(TreeNode* node, int& height){
        if (node == nullptr){
            height = -1;
            return true;
        }
        int left = 0;
        int right = 0;
        
        if (!bal(node->left, left) || !bal(node->right, right)) {
            return false;
        }
        if (left > right + 1 || right > left + 1) {
            return false;
        }
        
        height = 1 + max(left, right);
        return true;
    }
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return bal(root, height);
    }
};