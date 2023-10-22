/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    TreeNode * tmp;
    stack<TreeNode *> nodes;
    BSTIterator(TreeNode* root) {
        TreeNode * tmp = root;
        nodes.push(tmp);
        while(tmp->left){
            tmp = tmp->left;
            nodes.push(tmp);
        }
        //tmp->left = new TreeNode(tmp->val-1);
        //tmp = tmp->left;
    }
    
    int next() {
        TreeNode * res = nodes.top();
        TreeNode * n = res;
        nodes.pop();
        if(n->right){
            nodes.push(n->right);
            n = n->right;
            while(n->left){
                n = n->left;
                nodes.push(n);
            }
        }
        //cout << nodes.size()<<endl;
        return res->val;

    }
    
    bool hasNext() {
        return !nodes.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
