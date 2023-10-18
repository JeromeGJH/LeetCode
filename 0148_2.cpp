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
        ListNode * head1 = nullptr;
        ListNode * head2 = nullptr;
        ListNode * h1 = nullptr;
        ListNode * h2 = nullptr;
        //cout << "here1" <<endl;
        while(tmp){
            //cout << "here2" <<endl;
            if(tmp->val < pivot){
                if(head1 == nullptr){
                    head1 = tmp;
                    h1 = head1;
                    tmp = tmp->next;
                    h1->next = nullptr;
                    continue;
                }
                h1->next = tmp;
                tmp = tmp->next;
                h1 = h1->next;
                h1->next = nullptr;
            }else{
                if(head2 == nullptr){
                    head2 = tmp;
                    h2 = head2;
                    tmp = tmp->next;
                    h2->next = nullptr;
                    continue;
                }
                h2->next = tmp;
                tmp = tmp->next;
                h2 = h2->next;
                h2->next =nullptr;
            }
        }
        if(head1 == nullptr){
            head1 = head;
            h1 = head1;
        }else{
            h1->next = head;
        }
        head->next = nullptr;
        
        // tmp = head1;
        // while(tmp->next){
        //     tmp = tmp->next;
        //     cout << tmp->val <<endl;
        // }
        head1 = sortList(head1);
        head2 = sortList(head2);
        head->next = head2;

        return head1;
    }

};
