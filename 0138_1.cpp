/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr){
            return head;
        }
        vector<int> mark;
        Node * ans = new Node(0);
        Node * h = ans;
        Node * tail = head;
        Node * r;
        int cnt, i = 0;
        while(tail){
            //cout << tail->val<<endl;
            h->next = new Node(tail->val);
            h = h->next;

            r = tail->random;
            if(r == nullptr){
                cnt = -1;
                mark.emplace_back(cnt);
            }else{
                cnt = 1;
                while(r->next){
                    r = r->next;
                    ++cnt;
                }
                mark.emplace_back(cnt);
            }
            if(tail->next){
                tail = tail->next;
            }else{
                break;
            }
            ++i;
        }

        //cout << "here1" << endl;
        h = ans->next;
        int j;
        for(i = 0; i < mark.size(); ++i){
            r = ans;
            if(mark[i] > 0){
                for(j = 0; j <= mark.size() - mark[i]; ++j){
                    r = r->next;
                }
                h->random = r;
            }
            h = h->next;
        }
        return ans ->next;

        
    }
};
