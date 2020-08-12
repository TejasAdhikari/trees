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

int maxwidth(Node* root){
    if(root == NULL) return 0;

    queue<Node*> q;
    q.push(root);
    int result = 0, size = 0;
    
    while(!q.empty()){
        size = q.size();
        result = max(result, size);

        while(size--){
            Node* current = q.front();
            q.pop();
            if(current->left) q.push(current->left);
            if(current->right) q.push(current->right);
        }
    }
    return result;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<"max width is: "<<maxwidth(root);
    return 0;
}