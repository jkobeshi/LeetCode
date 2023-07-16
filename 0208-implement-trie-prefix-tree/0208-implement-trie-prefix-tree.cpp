class Node{
public:
    unordered_map<char, Node*> children;
    bool isWord;
    Node(){
        isWord = false;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
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
    
    bool search(string word) {
        Node* temp = root;
        for(int i = 0; i < word.size(); ++i){
            if (temp->children.find(word[i]) == temp->children.end()){
                return false;
            }
            temp = temp->children[word[i]];
        }
        return temp->isWord;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(int i = 0; i < prefix.size(); ++i){
            if (temp->children.find(prefix[i]) == temp->children.end()){
                return false;
            }
            temp = temp->children[prefix[i]];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */