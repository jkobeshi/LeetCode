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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* sum = new ListNode((l1->val + l2->val) % 10);
        ListNode* tempNext = sum;
        int carry = (l1->val + l2->val) / 10;
        while (l1->next != nullptr || l2->next != nullptr){
            tempNext->next = new ListNode(carry);
            if (l1->next == nullptr){
                l2 = l2->next;
                carry = (l2->val + tempNext->next->val) / 10;
                tempNext->next->val = (l2->val + tempNext->next->val) % 10;
            }
            else if (l2->next == nullptr){
                l1 = l1->next;
                carry = (l1->val + tempNext->next->val) / 10;
                tempNext->next->val = (l1->val + tempNext->next->val) % 10;
            }
            else{
                l2 = l2->next; l1 = l1->next;
                carry = (l1->val + l2->val + tempNext->next->val) / 10;
                tempNext->next->val = (l1->val + l2->val + tempNext->next->val) % 10;
            }
            tempNext = tempNext->next;
        }
        if (carry > 0){
            tempNext->next = new ListNode(carry);
        }
        return sum;
    }
};