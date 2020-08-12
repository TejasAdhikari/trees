#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = this->right = NULL;
    }
};

void range(Node* root, int n1, int n2){
    if(!root) return;

    if(root->left && root->data > n1) range(root->left, n1, n2);

    if(n1 <= root->data && root->data <= n2){
        cout<<root->data<<" ";
    }

    if(root->right && root->data < n2) range(root->right, n1, n2);
}

int main(){
    Node* root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(7);
    root1->right->right = new Node(8);
    root1->right->left = new Node(6);
    root1->left->right = new Node(4);
    root1->left->left = new Node(2);

    range(root1, 3, 5);

    return 0;
}