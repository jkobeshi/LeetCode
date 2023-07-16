/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* first;
        ListNode* revSecond = nullptr;
        int count = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            count++;
            temp = temp->next;
        }
        first = head;
        for(int i = 0; i < (count / 2) - 1; ++i){
            head = head->next;
        }
        temp = head;
        head = head->next;
        temp->next = nullptr;

        while(head != nullptr){
            temp = head;
            head = head->next;
            temp->next = revSecond;
            revSecond = temp;
        }
        while(first != nullptr && revSecond != nullptr){
            temp = first;
            first = first->next;
            temp->next = revSecond;
            revSecond = revSecond->next;
            temp = temp->next;
            temp->next = first;
        }
        if(revSecond != nullptr){
            temp->next = revSecond;
        }
    }
};