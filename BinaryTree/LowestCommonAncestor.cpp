#include<iostream>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v){
        val = v;
        left = nullptr;
        right = nullptr;
    }
};

class solution {
    public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL){
            return NULL;
        }

        if(root->val > p->val && root->val > q->val){
            return lowestCommonAncestor(root->left, p, q);
        } else if (root->val < p->val && root->val < q->val){
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }
    }
};


int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);

    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode* p = root->left;                 // node 5
    TreeNode* q = root->left->right->right;   // node 4

    solution sol;
    TreeNode* ans = sol.lowestCommonAncestor(root, p, q);

    if (ans)
        cout << "LCA = " << ans->val << "\n";
    else
        cout << "LCA not found\n";
    return 0;
}