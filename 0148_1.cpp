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
    // ListNode* mergeSort(ListNode * head){
        
    // }

    ListNode* sortList(ListNode* head) {
        if(head == nullptr){
            return head;
        }
        if(head->next == nullptr){
            return head;
        }
        ListNode * tmp = head->next;
        int pivot = head->val;
        ListNode * head1 = new ListNode(0, nullptr);
        ListNode * head2 = new ListNode(0, nullptr);
        ListNode * h1 = head1;
        ListNode * h2 = head2;
        //cout << "here1" <<endl;
        while(tmp){
            //cout << "here2" <<endl;
            if(tmp->val < pivot){
                h1->next = tmp;
                tmp = tmp->next;
                h1 = h1->next;
                h1->next = nullptr;
            }else{
                h2->next = tmp;
                tmp = tmp->next;
                h2 = h2->next;
                h2->next =nullptr;
            }

        }
        h1->next = head;
        head->next = nullptr;
        // tmp = head1;
        // while(tmp->next){
        //     tmp = tmp->next;
        //     cout << tmp->val <<endl;
        // }
        head1->next = sortList(head1->next);
        head2->next = sortList(head2->next);
        tmp = head1;
        while(tmp->next){
            tmp = tmp->next;
        }
        tmp->next = head2->next;

        return head1->next;
    }

};
