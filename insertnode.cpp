#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left, * right;

    Node(int data){
        this->data=data;
        left = right = NULL;
    }
};

void levelorder(Node* node){
    if(node == NULL) return;
    queue<Node*> q;
    q.push(node);

    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        cout<< current->data <<" ";

        if(current->left!=NULL)
            q.push(current->left);
        if(current->right!=NULL)
            q.push(current->right);
    }
}

void insertnode(Node* node, int key){
    queue<Node*> q;
    q.push(node);

    while (!q.empty())
    {
        Node* current = q.front();
        q.pop();

        if(!(current->left)){
            current->left = new Node(key);
            break;
        }
        else{
            q.push(current->left);
        }

        if(!(current->right)){
            current->right = new Node(key);
            break;
        }
        else{
            q.push(current->right);
        }
    }
    
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(6);

    levelorder(root);
    cout<<endl;

    insertnode(root, 5);
    levelorder(root);

    return 0;
}