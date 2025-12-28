// Largest Binary Search Tree In Binary Tree

#include<iostream>
using namespace std;


class Node {
    public:
    int val;
    Node* left;
    Node* right;

    Node(int v): val(v), left(NULL), right(NULL) {}
};

class Info {
    public:
    int min, max, size;

    Info(int mn, int mx, int sz){
        min = mn;
        max = mx;
        size = sz;
    }
};

Info helper(Node* root){
    if(root == NULL){
        return Info(INT_MAX, INT_MIN, 0);
    }
    Info left = helper(root->left);
    Info right = helper(root->right);

    if(root->val > left.max && root->val < right.min){
        int currMin = min(root->val, left.min);
        int currMax = max(root->val, right.max);
        int currSize = left.size + right.size + 1;

        return Info(currMin, currMax, currSize);
    }

    return Info(INT_MIN, INT_MAX, max(left.size, right.size));
}

int largestBSTInBT(Node* root) {
    Info ans = helper(root);
    return ans.size;
}


int main(){

    Node* root = new Node(10);

    root->left = new Node(5);
    root->right = new Node(15);

    root->left->left = new Node(1);
    root->left -> right = new Node(8);

    root->right->right = new Node(7);

    cout<<largestBSTInBT(root)<<endl;

    return 0;
}