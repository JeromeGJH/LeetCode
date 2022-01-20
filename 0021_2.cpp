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
    void merge(ListNode* p1, ListNode* p2) {
        if(p1->next == nullptr){
            p1->next = p2;
            return;
        }
        if(p2 == nullptr){
            return;
        }
        if(p1->next->val <= p2->val){
            return merge(p1->next, p2);
        }else{
            ListNode* tmp1 = p1->next;
            ListNode* tmp3 = p2->next;
            p1->next = p2;
            p2->next = tmp1;
            p1 = p2;
            return merge(p1, tmp3);
        }
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        if(p2 == nullptr){
            return p1;
        }
        if(p1 == nullptr){
            return p2;
        }
        if(p1->val <= p2->val){
            merge(p1, p2);
            return l1;
        }else{
            merge(p2, p1);
            return l2;
        }
    }
};
