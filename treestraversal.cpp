#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node (int data){
        this->data = data;
        this->left = this->right = NULL; 
    }
};

void levelOrder(Node* root){
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* current = q.front();
        cout<<current->data<<" ";
        q.pop();
        if(current->left) q.push(current->left);
        if(current->right) q.push(current->right);
    } 
}

void preOrder(Node* root){
    if(root==NULL) return;

    cout<<root->data<<" ";
    if(root->left) preOrder(root->left);
    if(root->right) preOrder (root->right);
}

void inOrder(Node* root){
    if(root==NULL) return;

    if(root->left) inOrder(root->left);
    cout<<root->data<<" ";
    if(root->right) inOrder(root->right);
}

void postOrder(Node* root){
    if(root == NULL) return;

    if(root->left) postOrder(root->left);
    if(root->right) postOrder(root->right);
    cout<<root->data<<" ";
}

void preOrder1 (Node* root){
    if(root == NULL) return;

    stack<Node*> s;
    s.push(root);
    while(!s.empty()){
        Node* current = s.top();
        cout<<current->data<<" ";
        s.pop();
        if(current->right) s.push(current->right);
        if(current->left) s.push(current->left);
    }
}

void inOrder1 (Node* root){
    if(root == NULL) return;

   
    stack<Node*> s;
    Node* current = root;
    while(true){
        if(current != NULL) {
            s.push(current);
            current = current->left;
        }
        else{
            if(s.empty()) return;
            cout<<s.top()->data<<" ";
            current = s.top()->right;
            s.pop();
        }

    }
}

void postOrder1(Node* root){
    if(root ==NULL) return;

    stack<Node*> s, result;
    s.push(root);
    while(!s.empty()){
        Node* current = s.top();
        s.pop();
        result.push(current);
        if(current->left) s.push(current->left);
        if(current->right) s.push(current->right);
    }
    while(!result.empty()){
        cout<<result.top()->data<<" ";
        result.pop();
    }
}





int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(6);
    root->left->right = new Node(5); 
    root->right->right = new Node(7);

    cout<<"level order traversal: ";
    levelOrder(root);
    cout<<endl;

    cout<<"pre order traversal: ";
    preOrder(root);
    cout<<endl;

    cout<<"in order traversal: ";
    inOrder(root);
    cout<<endl;

    cout<<"post order traversal: ";
    postOrder(root);
    cout<<endl;
    
    cout<<"pre order traversal: ";
    preOrder1(root);
    cout<<endl;

    cout<<"in order traversal: ";
    inOrder1(root);
    cout<<endl;

    cout<<"post order traversal: ";
    postOrder1(root);
    cout<<endl;

    return 0;
}
