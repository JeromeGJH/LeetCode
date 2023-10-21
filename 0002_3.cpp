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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * res = l1;
        int v1, v2, c=0;
        while(true){
            v1 = l1->val;
            v2 = l2->val;
            l1->val = (v1+v2+c)%10;
            //cout << l1->val<< endl;
            c = (v1+v2+c)/10;
            if(l1->next == nullptr){
                l1->next = l2->next;
                l2->next = nullptr;
                l2->val = 0;
                if(l1->next == nullptr){
                    if(c == 1){
                        l1->next = new ListNode(1, nullptr);
                    }
                    break;
                }else{
                    l1 = l1->next;
                }
            }else{
                l1 = l1->next;
                if(l2->next == nullptr){
                    l2->val = 0;
                }else{
                    l2 = l2->next;
                }
            }
        }
        return res;

    }
};
