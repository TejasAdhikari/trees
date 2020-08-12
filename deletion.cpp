#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left, *right;

    Node(int data){
        this->data=data;
        left = right = NULL;
    }
};

void traversal(Node* node){
    queue<Node*> q;
    q.push(node);

    while(!q.empty()){
        Node* current = q.front();
        cout<< current->data <<" ";
        q.pop();

        if(current->left!=NULL)
            q.push(current->left);
        if(current->right!=NULL)
            q.push(current->right);
    }
}

void delete_node(Node* node, Node* ){

}

void deletion(Node* node, int key)
int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    traversal(root);

}