#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        left=right=NULL;
    }
};

void iterativepreorder(Node* node){
    if(node == NULL) return;

    stack<Node*> s;
    s.push(node);
    Node* current;
    while(!s.empty()){
        current = s.top();
        cout<< current->data <<" ";
        s.pop();

        if(current->right != NULL)
            s.push(current->right);
        if(current->left != NULL)
            s.push(current->left);
    }
}

int main(){
    Node* root;
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

    iterativepreorder(root);

    return 0;
}