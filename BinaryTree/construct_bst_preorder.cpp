// Construct BST from Preorder

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


class Solution {
    public:
    TreeNode* helper(vector<int>& preorder, int &i, int upper){ // O(n)
        if(i >= preorder.size() || preorder[i] > upper){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = helper(preorder, i, root->val);
        root->right = helper(preorder, i, upper);
        return root;
    }

    TreeNode* constructBSTFromPreorder(vector<int>& preorder){
            int i = 0;
            return helper(preorder, i, INT_MAX);
    }
};



int main(){
    Solution* obj;
    vector<int> arr = {6, 3, 1, 4, 8, 9};
    TreeNode* ans = obj->constructBSTFromPreorder(arr);
    cout<<"root: "<<ans->val<<endl;
    return 0;
}