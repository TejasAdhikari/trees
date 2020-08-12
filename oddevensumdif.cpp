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

int diff(Node* root){
    if(!root) return 0;

    queue<Node*> q;
    q.push(root);
    int evesum = 0, oddsum = 0, level = 0, size = 0;

    while(!q.empty()){
        size = q.size();
        level++;
        while(size--){
            Node* current = q.front();
            q.pop();
            if(level % 2 == 0){
                evesum += current->data;
            } 
            else{
                oddsum += current->data;
            }

            if(current->left) q.push(current->left);
            if(current->right) q.push(current->right);
        }
    }

    return (oddsum - evesum);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<"difference of odd and even level nodes is: "<<diff(root);
    return 0;
}