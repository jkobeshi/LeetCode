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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* newHead = head;
        ListNode* pre;
        while (head != nullptr){
            pre = head;
            head = head->next;
            while (head != nullptr && head->val == pre->val){
                ListNode* toDel = head;
                head = head->next;
                pre->next = head;
                delete toDel;
            }
        }
        return newHead;
    }
};