/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
unordered_map<int, Node*> seen;
class Solution {
public:
    Node* cloning(Node* node){
        if(node == nullptr){
            return nullptr;
        }
        if(seen.find(node->val) != seen.end()){
            return seen[node->val];
        }
        Node* clone = new Node(node->val);
        seen[node->val] = clone;
        for(int i = 0; i < node->neighbors.size(); ++i){
            clone->neighbors.push_back(cloning(node->neighbors[i]));
        }
        return clone;
    }
    Node* cloneGraph(Node* node) {
        Node* clone = cloning(node);
        seen.clear();
        return clone;
    }
};