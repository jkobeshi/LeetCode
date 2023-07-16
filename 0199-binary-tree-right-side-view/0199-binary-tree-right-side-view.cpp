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
    void height(TreeNode* node, int level){
        if(node == nullptr){
            return;
        }
        if(level == res.size()){
            res.push_back(node->val);
        }
        height(node->right, level + 1);
        height(node->left, level + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        height(root, 0);
        return res;
    }
};