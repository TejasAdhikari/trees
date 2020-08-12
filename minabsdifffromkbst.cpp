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

Node* mdiff(Node* root, int k, Node* closestNode){
    if(!root) return closestNode;

    if(root->data == k){
        return root;
    }
    if(!closestNode || abs(root->data - k) < abs(closestNode->data - k)){
        closestNode = root;
    }
    if(root->data < k) 
        return mdiff(root->right, k, closestNode);
    if(root->data > k) 
        return mdiff(root->left, k, closestNode);

}

int main(){
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->right->right = new Node(7);
    root->right->left = new Node(5);
    root->left->right = new Node(3);
    root->left->left = new Node(1);

    Node* ans = mdiff(root, 8, NULL);
    cout<<ans->data;

    return 0;
}