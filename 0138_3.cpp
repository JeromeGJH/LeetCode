class Solution {
public:
    unordered_map<Node*, Node*> cachedNode;

    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        Node * h = head;
        Node * tmp;
        Node * r;
        while(h){
            tmp = h->next;

            h->next = new Node(h->val);
            h = h->next;
            h->next = tmp;
            
            if(tmp == nullptr){
                break;
            }
            h = h->next;

        }
        h = head;
        while(h){
            tmp = h->next;
            if(h->random){
                r = h->random->next;
            }else{
                r = nullptr;
            }
            tmp->random = r;
            h = tmp->next;
            
        }

        Node * ans = new Node(0);
        r = ans;
        tmp = ans;
        h = head;
        while(h){
            tmp = h->next;
            r->next = tmp;
            r = r->next;
            h->next = h->next->next;
            h = h->next;
        }
        // h = ans;
        // while(h){
        //     cout << h->val << endl;
        //     h = h->next;
        // }
        return ans->next;
    }
};
