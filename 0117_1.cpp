/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    vector<vector<Node*>> level;

    void insert(Node* root, int d) {
        if(level.size() < d){
            level.emplace_back(vector<Node*>());
        }
        level[d-1].emplace_back(root);
        if(root->left){
            insert(root->left, d+1);
        }
        if(root->right){
            insert(root->right, d+1);
        }
        return;  
    }

    Node* connect(Node* root) {
        if(root == nullptr){
            return root;
        }
        insert(root, 1);
        int i = 0, j = 0;
        for(i = 0; i < level.size(); ++i){
            for(j = 0; j < level[i].size()-1; ++j){
                level[i][j]->next = level[i][j+1];
            }
        }
        return root;
        
    }
};
