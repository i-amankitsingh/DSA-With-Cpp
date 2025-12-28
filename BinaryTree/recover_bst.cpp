// Recover BST (Fix the swaped vlaues of node)

#include<iostream>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr){}
};

class Solution {
    public:

    TreeNode* prev;
    TreeNode* first;
    TreeNode* second;

    void inorder(TreeNode* root){ // TC O(n) SC O(n)
        if(root == NULL){
            return;
        }
        inorder(root->left);
        if(prev != NULL && root->val < prev->val){
            if(first == NULL){
                first = prev;
            }
            second = root;
        }
        prev = root;
        inorder(root->right);
    }

    void recoverBST(TreeNode* root){
        inorder(root);
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
    }
};

int main() {
    TreeNode* root = new TreeNode(6);
    
    root->left = new TreeNode(3);
    root->right = new TreeNode(4);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);

    root->right->right = new TreeNode(9);

    Solution* obj;
    obj->recoverBST(root);
    return 0;
}