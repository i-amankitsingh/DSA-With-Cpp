// Populate next right pointer in each node

#include<iostream>
using namespace std;

class Node {
    public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node(int v): val(v), left(NULL), right(NULL), next(NULL) {}  
};

class Solution {
    public:
    Node* connect(Node* root){
        if(root == NULL || root->left == NULL){
            return root;
        }

        queue<Node*> q;
        q.push(root);
        q.push(NULL); // Mark the end of the level

        Node* prev = NULL;

        while(q.size() > 0){
            Node* curr = q.front();
            q.pop();

            if(curr == NULL){
                if(q.size() == 0){
                    break;
                }
                q.push(NULL);
            } else {
                if(curr->left != NULL){
                    q.push(curr->left);
                } 
                if(curr->right != NULL){
                    q.push(curr->right);
                }
                if(prev != NULL){
                    prev->next = curr;
                }
            }
            prev = curr;
        }
        return root;
    }
};

int main(){
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution* sol = new Solution();

    Node* ans = sol->connect(root);

    cout<<ans->left->next->val<<endl;

    return 0;
}