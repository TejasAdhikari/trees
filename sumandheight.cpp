#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        this->left = this->right = NULL;
    }
};

int sum(Node* root){
    if(root == NULL) return 0;

    int sum = 0;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        sum +=current->data;
        if(current -> left) q.push(current->left);
        if(current->right) q.push(current->right);
    }
    return sum;
}

int heightr(Node* root){
    if(root == NULL) return 0;
    return(max(heightr(root->left), heightr(root->right))+1);
}

int heighti(Node* root){
    if(root == NULL) return 0;
    int height =  0, size = 0; 

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        size = q.size();
        while(size--){
            Node* current = q.front();
            q.pop();
            if(current->left) q.push(current->left);
            if(current->right) q.push(current->right);
        }
        height++;
    }
    return height;
}

int main(){
    Node* root =  new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<"sum is: "<<sum(root)<<endl;
    cout<<"height is: "<<heightr(root)<<endl;
    cout<<"height is: "<<heighti(root);
}