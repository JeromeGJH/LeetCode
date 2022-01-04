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
        ListNode* s = head;
        ListNode* e = head;
        for(int i = 0; i < n; ++i){
            e = e->next;
        }
        if(e == nullptr){
            return head->next;
        }else{
            while(e->next != nullptr){
                e = e->next;
                s = s->next;
            }
            s->next = s->next->next;
            return head;
        }
    }
};
