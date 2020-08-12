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

void left(Node* root){
    if (root == NULL) return;

    if(root->left){
        cout<<root->data<<" ";
        left(root->left);
    }
    else if(root->right){
        cout<<root->data<<" ";
        left(root->right);
    }
}

void right(Node* root){
    if(root == NULL) return;

    if(root->right){
        right(root->right);
        cout<<root->data<<" ";
    }
    else if(root->left){
        right(root->left);
        cout<<root->data<<" ";
    }
}

void leaves(Node* root){
    if(root == NULL) return;

    leaves(root->left);
    if(!(root->left) && !(root->right)){
        cout<<root->data<<" ";
    }
    leaves(root->right);
}

void boundary(Node* root){
    if(root == NULL) return;

    cout<<root->data<<" ";

    left(root->left);
    leaves(root->left);
    leaves(root->right);
    right(root->right);

    cout<<endl;
}

void corner(Node* root){
    if(root == NULL) return;
    
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            Node* current = q.front();
            q.pop();
            if(i == 0 || i == size-1){
                cout<<current->data<<" ";
            }
            if(current->left) q.push(current->left);
            if(current->right) q.push(current->right);
        }
    }
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<"boundaries are: ";
    boundary(root);

    cout<<"corners are: ";
    corner(root);

    return 0;
}