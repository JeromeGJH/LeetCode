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
    ListNode* mergeTwoLists(ListNode* p1, ListNode* p2) {
        if(p2 == nullptr){
            return p1;
        }
        if(p1 == nullptr){
            return p2;
        }

        ListNode* head;
        ListNode* tail;
        if(p1->val <= p2->val){
            head = p1;
            tail = p1;
            p1 = p1->next;
        }else{
            head = p2;
            tail = p2;
            p2 = p2->next;
        }
        while(true){
            if(p1 == nullptr){
                tail->next = p2;
                return head;
            }
            if(p2 == nullptr){
                tail->next = p1;
                return head;
            }
            if(p1->val <= p2->val){
                tail->next = p1;
                p1 = p1->next;
            }else{
                tail->next = p2;
                p2 = p2->next;
            }
            tail = tail->next;
        }
    }
};
