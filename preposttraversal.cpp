#include <bits/stdc++.h>
using namespace std;

struct Node{
            int data;
            Node* left;
            Node* right;

            Node (int data){
                this->data = data;
                left = right = NULL;
            } 
};

void preorder(Node *node){
    if(node == NULL) return;
    cout<<node->data<<endl;
    preorder(node->left);
    preorder(node->right);
}

int main(){
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

    cout<<"the pre order traversal is "<<endl;
    preorder(root);
    return 0;
}