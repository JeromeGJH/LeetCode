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
    ListNode* exchange(ListNode* n1, ListNode* n2){
        ListNode* tmp = n2->next;
        n2->next = n1;
        n1->next = tmp;
        return n2;
    }


    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        ListNode* h = exchange(p1, p2);
        p1 = h;
        p2 = h->next;
        while(p2->next != nullptr){
            if(p2->next->next != nullptr){
                p2->next = exchange(p2->next, p2->next->next);
                p1 = p2->next;
                p2 = p1->next; 
            }else{
                break;
            }
        }
        return h;
    }
};
