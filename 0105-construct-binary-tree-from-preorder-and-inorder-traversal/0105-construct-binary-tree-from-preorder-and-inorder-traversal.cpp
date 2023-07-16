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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i = 0;
        while(inorder[i] != preorder.front()) ++i;
        preorder.erase(preorder.begin());
        TreeNode* leftT = nullptr;
        TreeNode* rightT = nullptr;
        if(i != 0){
            vector<int> left(inorder.begin(), inorder.begin() + i);
            leftT = buildTree(preorder, left);
        }
        if((i + 1) < inorder.size()){
            vector<int> right(inorder.begin() + i + 1, inorder.end());
            rightT = buildTree(preorder, right);
        }
        return new TreeNode(inorder[i], leftT, rightT);
    }
};