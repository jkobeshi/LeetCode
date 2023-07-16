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
    int numGood = 0;
    void goodNode(TreeNode* node, int greatPath){
        if(node == nullptr){
            return;
        }
        if(node->val >= greatPath){
            numGood++;
            greatPath = node->val;
        }
        goodNode(node->left, greatPath);
        goodNode(node->right, greatPath);
    }

    int goodNodes(TreeNode* root) {
        goodNode(root, root->val);
        return numGood;
    }
};