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
        if(p1->next==nullptr){
            p1->next = p2;
            return;
        }
        if(p1->next->val <= p2->val){
            merge(p1->next, p2);
        }else{
            if(p2->next == nullptr){
                p2->next = p1->next;
                p1->next = p2;
            }else{
                ListNode* tmp = p2->next;
                p2->next = p1->next;
                p1->next = p2;
                merge(p2, tmp);
            }
        }
        return;
    }


    ListNode* divide(vector<ListNode*>& lists){
        //cout << "list size" << lists.size()<<endl;
        if(lists.size() == 1){
            return lists[0];
        }
        if(lists.size() == 2){
            if(lists[0]->val <= lists[1]->val){
                merge(lists[0], lists[1]);
                return lists[0];
            }else{
                merge(lists[1], lists[0]);
                return lists[1];
            }
        }else{
            int length = lists.size();
            std::vector<ListNode*> lists2;
            for(int i = 0; i < length/2; ++i){
                lists2.emplace_back(lists.back());
                lists.pop_back();
            }
            ListNode * h1 = divide(lists);
            ListNode * h2 = divide(lists2);
            if(h1->val <= h2->val){
                merge(h1, h2);
                return h1;
            }else{
                merge(h2, h1);
                return h2;
            }
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::vector<ListNode*> ls;
        for(int i = 0; i < lists.size(); ++i){
            if(lists[i] == nullptr){
                continue;
            }
            ls.emplace_back(lists[i]);
        }
        int len = ls.size();
        if(len == 0){
            return nullptr;
        }
        if(len == 1){
            return ls[0];
        }
        return divide(ls);
    }
};
