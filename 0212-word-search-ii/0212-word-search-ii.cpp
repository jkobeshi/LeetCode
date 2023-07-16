class Solution {
public:
    class Node{
    public:
        unordered_map<char, Node*> children;
        bool isWord;
        Node(){
            isWord = false;
        }
    };

    vector<string> res;
    Node* root = new Node();

    void insert(string word) { 
        Node* temp = root;
        for(int i = 0; i < word.size(); ++i){
            if(temp->children.find(word[i]) == temp->children.end()){
                temp->children[word[i]] = new Node();
            }
            temp = temp->children[word[i]];
        }
        temp->isWord = true;
    }
    
    void find(vector<vector<char>>& board, pair<int, int> ind, string word, Node* node){
        if(ind.first < 0 || ind.first >= board.size() ||
            ind.second < 0 || ind.second >= board[0].size() ||
            board[ind.first][ind.second] == '!'){
                return;
        }
        char original = board[ind.first][ind.second];
        if (node->children.find(original) == node->children.end()){
            return;
        }
        word = word + string(1, original);
        node = node->children[original];
        if(node->isWord){
            res.push_back(word);
            node->isWord = false;
        }
        board[ind.first][ind.second] = '!';
        find(board, pair(ind.first + 1, ind.second), word, node);
        find(board, pair(ind.first - 1, ind.second), word, node);
        find(board, pair(ind.first, ind.second + 1), word, node);
        find(board, pair(ind.first, ind.second - 1), word, node);
        board[ind.first][ind.second] = original;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            insert(words[i]);
        }
        for (int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                find(board, pair(i, j), "", root);
            }
        }
        return res;
    }
};