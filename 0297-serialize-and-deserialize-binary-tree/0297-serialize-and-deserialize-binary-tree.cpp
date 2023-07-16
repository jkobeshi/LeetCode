/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    string ser(TreeNode* root, string k){
        if(root == nullptr){
            return "";
        }
        string l = ser(root->left, k+"l");
        string r = ser(root->right, k+"r");
        return k + to_string(root->val) + l + r;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return ser(root, "");
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0){
            return nullptr;
        }
        int i = 0;
        while(i < data.size() && data[i] != 'l' &&  data[i] != 'r'){
            ++i;
        }
        TreeNode* tree = new TreeNode(stoi(data.substr(0, i + 1)));
        TreeNode* temp = tree;
        TreeNode* prev;
        while(i < data.size()){
            char last = 'x';
            while(i < data.size() && (data[i] == 'l' || data[i] == 'r')){
                last = data[i];
                prev = temp;
                if(data[i] == 'l'){
                    temp = temp->left;
                }
                if(data[i] == 'r'){
                    temp = temp->right;
                }
                ++i;
            }
            int oldi = i;
            while((i < data.size()) && (data[i] != 'l' && data[i] != 'r')){
                ++i;
            }
            if(last == 'l'){
                prev->left = new TreeNode(stoi(data.substr(oldi, i - oldi + 1)));
            }
            else{
                prev->right = new TreeNode(stoi(data.substr(oldi, i - oldi + 1)));
            }
            temp = tree;
        }
        return tree;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));