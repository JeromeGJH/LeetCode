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
        ListNode * tmp = new ListNode(0, head);
        pre = tmp;
        while(h){
            cout << h->val << endl;
            if(h->next == nullptr){
                pre->next = h;
                break;
            }else{
                if(h->next->val == h->val){
                    while(h->next){
                        if(h->next->val == h->val){
                            h = h->next;
                            if(h->next == nullptr){
                                h = nullptr;
                                break;
                            }
                        }else{
                            h = h->next;
                            if(h->next == nullptr || h->next->val != h->val){
                                break;
                            }
                        }
                    }
                    pre->next = h;
                    pre = h;
                    if(!h){
                        break;
                    }

                    h = h->next;
                    pre->next = nullptr;
                    
                }else{
                    pre->next = h;
                    pre = h;
                    h = h->next;
                    pre->next = nullptr;
                }
            }
            
            
        }
        return tmp->next;;


    }
};
