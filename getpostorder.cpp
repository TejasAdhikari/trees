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

minLevelLeavesSum(Node* root){
    if(!root) return 0;

    queue<Node*> q;
    q.push(root);

    if(!root->left && !root->right) return root->data;

    int sum = 0;
    bool f = 0;

    while(f == 0){
        int size = q.size();
        while(size--){
            Node* current = q.front();
            q.pop();
            if(!current->left && !current->right){
                sum += current->data;
                f = 1;
            }
            else{
                if(current->left) q.push(current->left);
                if(current->right) q.push(current->right);
            }
        }
    }
    return sum;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<"the sum of the minimum level leaf nodes: "<<minLevelLeavesSum(root);
    return 0;
}