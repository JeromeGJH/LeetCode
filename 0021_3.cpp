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
            tmp = list2;
            list2 = list1;
            list1 = tmp;
        }
        ans = list1;
            
        while(true){
            if(list1->val <= list2->val){
                if(list1->next == nullptr){
                    list1->next = list2;
                    break;
                }else{
                    if(list1->next->val >= list2->val){
                        tmp = list2;
                        list2 = list2->next;
                        tmp->next = list1->next;
                        list1->next = tmp;
                        list1 = tmp;
                        if(list2 == nullptr){
                        break;
                    }
                    }else{
                        list1 = list1->next;
                    }
                    
                    
                }
            }
           
        }

        
        return ans;
        
        
    }
};
