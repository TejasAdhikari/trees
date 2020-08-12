#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        left = right = NULL;
    }
};

void iterativepostorder(Node* node){
    if(node==NULL) return;
    stack<Node*> s,r;
    s.push(node);
   
    while (!s.empty())
    {
        Node* current = s.top();
        s.pop();
        r.push(current);

        if(current->left!=NULL)
            s.push(current->left);
        if(current->right!=NULL)
            s.push(current->right);
    }

    while (!r.empty())
    {
        cout<< r.top()->data << " ";
        r.pop();
    }
}

int main(){
    Node* root = new Node(1);
    root ->left = new Node(2);
    root ->right = new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->right=new Node(6);

    iterativepostorder(root);
    return 0;
}