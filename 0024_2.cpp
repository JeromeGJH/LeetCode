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
    ListNode* swapPairs(ListNode* head) {
        ListNode * ans =  new ListNode(0, head);
        ListNode * n1;
        ListNode * n2;
        ListNode * tmp;
        n1 = ans;
        n2 = head;
        if(head == nullptr){
            return head;
        }
        if(head->next == nullptr){
            return head;
        }
        while(n2->next){
            tmp = n2->next;
            n2->next = n2->next->next;
            tmp->next = n2;
            n1->next = tmp;

            n1 = n2;
            if(n1->next == nullptr){
                break;
            }else{
                n2 = n1->next;

            }
            

        }

        return ans->next;

    }
};
