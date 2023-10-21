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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right){
            return head;
        }
        vector<ListNode *> nodes;
        ListNode * tmp = new ListNode(0, head);
        ListNode * h = tmp, * tail;
        int flag = 0;
        int i = 0;
        while(h){
            if(i >= left-1 && i <= right){
                nodes.emplace_back(h);
            }
            if(i == right){
                tail = h->next;
            }
            ++i;
            h = h->next;
        }
        for(i = nodes.size()-1; i > 0; --i){
            nodes[i]->next = nodes[i-1];
        }
        nodes[0]->next = nodes[nodes.size()-1];
        nodes[1]->next = tail;
        return tmp->next;

    }
};
