/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> maps;
        Node* temp = head;
        while(temp != nullptr){
            maps[temp] = new Node(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp != nullptr){
            Node* copy = maps[temp];
            copy->next = maps[temp->next];
            copy->random = maps[temp->random];
            temp = temp->next;
        }
        return maps[head];
    }
};