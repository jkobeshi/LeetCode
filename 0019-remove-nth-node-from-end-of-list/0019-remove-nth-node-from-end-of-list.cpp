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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode* it = head;
        while(it != nullptr){
            it = it->next;
            ++cnt;
        }
        int i = 0;
        it = head;
        ListNode* prev = nullptr;
        while(i < cnt - n){
            prev = it;
            it = it->next;
            ++i;
        }
        if(prev == nullptr){
            return it->next;
        }
        prev->next = it->next;
        delete it;
        return head;
    }
};