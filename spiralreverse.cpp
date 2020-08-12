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

void spiral(Node* root){
    if(root == NULL) return;

    stack<Node*> s1, s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            Node* current = s1.top();
            cout<< current->data<<" ";
            s1.pop();
            if(current->right) s2.push(current->right);
            if(current->left) s2.push(current->left);
        }
        while(!s2.empty()){
            Node* current = s2.top();
            cout<< current->data<<" ";
            s2.pop();
            if(current->left) s1.push(current->left);
            if(current->right) s1.push(current->right);
        }
    }

}

void reverse(Node* root){
    if(root == NULL) return;

    queue<Node*> q;
    stack<Node*> s;
    q.push(root);
    while(!q.empty()){
        Node* current = q.front();
        s.push(current);
        q.pop();
        if(current->right) q.push(current->right);
        if(current->left) q.push(current->left);
    }
    while(!s.empty()){
        cout<<s.top()->data<<" ";
        s.pop();
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

    cout<<"spiral print: ";
    spiral(root);
    cout<<endl<<"reverse print: ";
    reverse(root);

    return 0;
}