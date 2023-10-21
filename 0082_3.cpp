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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr){
            return head;
        }
        ListNode * h = head;
        ListNode * pre;
        ListNode * ans = new ListNode(101, head);
        pre = ans;
        ListNode * tmp = ans;
        while(h){
            if(h->next == nullptr){
                if(h->val == pre->val){
                    h = nullptr;
                }
                tmp->next = h;
                break;
            }else{
                if(h->val == h->next->val){
                    pre = h;
                    h = h->next;
                }else{
                    if(h->val == pre->val){
                        pre = h;
                        h = h->next;
                    }else{
                        tmp->next = h;
                        tmp = h;
                        pre = h;
                        h = h->next;
                    }
                }
            }
        }
        return ans->next;;
    }
};
