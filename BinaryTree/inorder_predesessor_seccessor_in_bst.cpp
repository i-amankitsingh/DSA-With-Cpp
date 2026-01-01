// Inorder predesessor and successor in BST

#include<iostream>
using namespace std;

class Node {
    public:
    int val;
    Node* left;
    Node* right;

    Node(int v): val(v), left(NULL), right(NULL) {}
};

Node* rightMostInLeftSubTree(Node* root){
    if(root == NULL) return NULL;

    if(root->right == NULL){
        return root;
    }
    return rightMostInLeftSubTree(root->right);
}

Node* leftMostInRightSubTree(Node* root){
    Node* ans;
    while(root != NULL){
        ans = root;
        root = root->left;
    }

    return ans;
}

vector<int> getPredSucc(Node* root, int key) {
    Node* curr = root;
    Node* pred = NULL;
    Node* succ = NULL;

    while(curr != NULL){
        if(curr->val > key){
            succ = curr;
            curr = curr->left;
        } else if(curr->val < key){
            pred = curr;
            curr = curr->right;
        } else{
            if(curr->left != NULL){
                pred = rightMostInLeftSubTree(curr->left);
            }

            if(curr->right != NULL){
                succ = leftMostInRightSubTree(curr->right);
            }
            break;
        }
    }
    return {pred->val, succ->val};
}

int main(){

    Node* root = new Node(6);

    root->left = new Node(4);
    root->right = new Node(8);

    root->left->left = new Node(1);
    root->left->right = new Node(5);

    root->right->left = new Node(7);
    root->right->right = new Node(9);

    int key = 7;

    vector<int> ans = getPredSucc(root, key);

    cout<<"Predesessor: "<<ans[0]<<endl;
    cout<<"Successor: "<<ans[1]<<endl;

    return 0;
}