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
        if(list1 == nullptr){
            return list2;
        }
        if(list2 == nullptr){
            return list1;
        }
        ListNode * ans;
        ListNode * tmp;
        
        if(list2->val < list1->val){
            ans = list2;
            list2 = list2->next;
        }else{
            ans = list1;
            list1 = list1->next;
        }
        tmp = ans;
        while(true){
            if(list1 == nullptr){
                tmp->next = list2;
                break;
            }
            if(list2 == nullptr){
                tmp->next = list1;
                break;
            }
            if(list1->val <= list2->val){
                tmp->next = list1;
                list1 = list1->next;
            }else{
                tmp->next = list2;
                list2 = list2->next;
            }
            tmp = tmp->next;

        }

        
        return ans;
        
        
    }
};
