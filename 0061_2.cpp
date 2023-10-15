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
        ListNode * pre = ans;
        while(h->next){
            l += 1;
            h = h->next;
        }
        int loop = k%l;
        if(loop == 0){
            return head;
        }

        for(i = 0; i< l-loop; ++i){
            pre = pre->next;
        }
        tmp1 = pre->next;
        pre->next = nullptr;
        h->next = head;
        
        return tmp1;

    }
};
