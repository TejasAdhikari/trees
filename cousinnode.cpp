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

bool cousin(Node* root, Node* a, Node* b){
    if(!root) return false;

    Node* parent_A = NULL;
    Node* parent_B = NULL;

    queue<pair<Node*, Node*>> q;

    pair<Node*, Node*> ele;

    Node* temp = new Node(-1);

    q.push(make_pair(root, temp));

    int size;
    while(!q.empty()){
        size = q.size();

        while(size--){
            ele = q.front(); q.pop();
            if(ele.first->data == a->data)
                parent_A = ele.second;
            if(ele.first->data == b->data)
                parent_B = ele.second;
            
            if(ele.first->left) 
                q.push(make_pair(ele.first->left, ele.first));
            if(ele.first->right)
                q.push(make_pair(ele.first->right, ele.first));
            
            if(parent_A && parent_B)
                break;
        }

        if(parent_A && parent_B)
            return parent_A != parent_B;
        
        if((parent_A && !parent_B) || (!parent_A && parent_B))
            return false;
    }
    return false;
}

int main(){
    Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 

    Node* a = new Node(4);
    Node* b = new Node(7);

    if(cousin(root, a, b)){
        cout<<"True";
    }
    else{
        cout<<"False";
    }

    return 0;
}