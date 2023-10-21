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
        ListNode * tmp = new ListNode(101, head);
        pre = tmp;
        vector<int> mark;
        while(h){
            if(h->next == nullptr){
                if(h->val == pre->val){
                    mark.emplace_back(1);
                }else{
                    mark.emplace_back(0);
                }
                break;
            }else{
                if(h->val == h->next->val){
                    mark.emplace_back(1);
                }else{
                    if(h->val == pre->val){
                        mark.emplace_back(1);
                    }else{
                        mark.emplace_back(0);
                    }
                    
                }
            }
            pre = h;
            h = h->next;
            
            
        }
        int i = 0;
        pre = tmp;
        h = head;
        for(i = 0; i < mark.size(); ++i){
            if(mark[i] == 0){
                pre->next = h;
                pre = pre->next;
            }
            h = h->next;
        }
        if(mark[mark.size()-1] == 1){
            pre->next = nullptr;

        }
        return tmp->next;;


    }
};
