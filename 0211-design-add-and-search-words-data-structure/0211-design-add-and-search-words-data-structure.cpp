class TrieNode{
public:
    unordered_map<char, TrieNode*> children;
    bool isWord;
    TrieNode() {
        isWord = false;
    }
};

class WordDictionary {
private:
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* temp = root;
        for(int i = 0; i < word.size(); ++i){
            if(temp->children.find(word[i]) == temp->children.end()){
                temp->children[word[i]] = new TrieNode();
            }
            temp = temp->children[word[i]];
        }
        temp->isWord = true;
    }
    
    bool recSearch(string word, TrieNode* node, int i){
        if (node == nullptr){
            return false;
        }
        if (i == word.size()){
            return node->isWord;
        }
        if (word[i] != '.'){
            if(node->children.find(word[i]) == node->children.end()){
                return false;
            }
            return recSearch(word, node->children[word[i]], i + 1);
        }
        for(auto it = node->children.begin(); it != node->children.end(); ++it){
            if (recSearch(word, it->second, i + 1)){
                return true;
            }
        }
        return false;
    }

    bool search(string word) {
        return recSearch(word, root, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */