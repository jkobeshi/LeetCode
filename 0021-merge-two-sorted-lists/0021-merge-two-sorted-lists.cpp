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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* merged;
        if(list1 == nullptr ){
            return list2;
        }
        if(list2 == nullptr){
            return list1;
        }
        if(list1->val > list2->val){
            merged = list2;
            list2 = list2->next;
        }
        else{
            merged = list1;
            list1 = list1->next;
        }
        ListNode* ind = merged;
        while(list1 != nullptr && list2 != nullptr){
            ListNode* temp;
            if (list1->val > list2->val){
                temp = list2;
                list2 = list2->next;
                ind->next = temp;
            }
            else{
                temp = list1;
                list1 = list1->next;
                ind->next = temp;
            }
            ind = ind->next;
        }
        if(list1 != nullptr){
            ind->next = list1;
        }
        if(list2 != nullptr){
            ind->next = list2;
        }
        return merged;
    }
};