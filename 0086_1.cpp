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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr){
            return head;
        }
        if(head->next == nullptr){
            return head;
        }
        ListNode * h1 = new ListNode(0);
        ListNode * h2 = new ListNode(0);
        ListNode * h = head;
        ListNode * tmp1, * tmp2;
        tmp1 = h1;
        tmp2 = h2;
        while(h){
            if(h->val < x){
                tmp1->next = h;
                h = h->next;
                tmp1 = tmp1->next;
                tmp1->next = nullptr;
            }else{
                tmp2->next = h;
                h = h->next;
                tmp2 = tmp2->next;
                tmp2->next = nullptr;
            }
        }
        tmp1->next = h2->next;
        return h1->next;

    }
};
