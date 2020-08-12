#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        left = right = NULL;
    }
};

void iterativeinorder(Node* node){
    Node* current = node;
    stack<Node*> s;
    while(!s.empty()){
        if(current != NULL){
            s.push(current);
            current = current->left;
        }
        else{
            if(s.empty()) break;
            cout << s.top()->data << " ";
            current = s.top()->right;
            s.pop();
        }
    }
}

int main(){
    Node* root;
    root = new Node(1);
    root -> left = new Node(2);
    root -> right = new Node(3);
    root -> left -> left = new Node(4);
    root -> left -> right = new Node(5);
    root -> right -> right = new Node(6);
    
    iterativeinorder(root);
    return 0;
}