// BST Iterator

#include<iostream>
#include<stack>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v): val(v), left(NULL), right(NULL) {}
};

class Solution {
    public:
    stack<TreeNode*> s;

    void storeLeftNodes(TreeNode* root){
        while(root != NULL){
            s.push(root);
            root = root->left;
        }
    }

    void BSTIterator(TreeNode* root){
        storeLeftNodes(root);
    }

    int next(){ // O(1) avg time complexity
        TreeNode* ans = s.top();
        s.pop();

        storeLeftNodes(ans->right);

        return ans->val;

    }
    
    bool hasNext(){
        return s.size() > 0;
    }
};

int main(){
    TreeNode* root = new TreeNode(7);

    root->left = new TreeNode(3);
    root->right = new TreeNode(15);

    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    Solution* sol = new Solution();
    sol->BSTIterator(root);
    int ans = sol->next();
    cout<<"ans: "<<ans<<endl;

    return 0;
}