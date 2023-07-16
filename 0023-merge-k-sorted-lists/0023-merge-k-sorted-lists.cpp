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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        ListNode* merged = nullptr; int k = -1;
        for(int i = 0; i < lists.size(); ++i){
            if(lists[i] == nullptr){
                lists.erase(lists.begin() + i);
                --i;
            }
            else if (merged == nullptr || lists[i]->val < merged->val){
                merged = lists[i]; k = i;
            }
        }
        ListNode* ind = merged;
        if(k != -1){
            lists[k] = lists[k]->next;
            if(lists[k] == nullptr){
                lists.erase(lists.begin() + k);
            }
        }
        while(!lists.empty()){
            ListNode* min = lists[0]; int j = 0;
            for(int i = 1; i < lists.size(); ++i){
                if(lists[i]->val < min->val){
                    min = lists[i];
                    j = i;
                }
            }
            lists[j] = lists[j]->next;
            if(lists[j] == nullptr){
                lists.erase(lists.begin() + j);
            }
            ind->next = min;
            ind = ind->next;
        }
        return merged;
    }
};