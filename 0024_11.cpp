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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr){
            return head;
        }
        if(head->next == nullptr){
            return head;
        }
        int i = 0;
        ListNode * ans = new ListNode(0, head);
        ListNode * tmp1 = head;
        ListNode * h = head;
        int l = 1;
        ListNode * pre;
        while(h->next){
            l += 1;
            h = h->next;
        }
        int loop = k%l;
        for(i = 0; i < loop; ++i){
            tmp1 = ans->next;
            h = tmp1;
            while(h->next){
                pre = h;
                h = h->next;
            }
            pre->next = nullptr;
            h->next = tmp1;
            ans->next = h;
        }
        return ans->next;

    }
};
