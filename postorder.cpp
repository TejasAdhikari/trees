#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;

    Node(int data){
        this->data = data;
        left = right = NULL;
    }
};

void postorder(Node *node){
    if(node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<endl;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

    cout<<"the post orer traversal is "<<endl;
    postorder(root);
    return 0;
}