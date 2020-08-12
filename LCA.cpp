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

Node* findLCAutil(Node* root, int n1, int n2, bool &v1, bool &v2){
    if(!root) return NULL;

    if(root->data == n1){
        v1 = true; 
        return root;
    }
    if(root->data == n2){
        v2 = true;
        return root;
    }

    Node* l_lca = findLCAutil(root->left, n1, n2, v1, v2);
    Node* r_lca = findLCAutil(root->right, n1, n2, v1, v2);

    if(l_lca && r_lca) return root;

    return(l_lca) ? l_lca : r_lca; 
}

bool find(Node* root, int k){
    if(!root) return false;
    
    if(root->data == k || find(root->left, k) || find(root->right, k)){
        return true;
    }
    else{
        return false;
    }
}

Node* findLCA(Node* root, int n1, int n2){
    bool v1 = false, v2 = false;

    Node* lca = findLCAutil(root, n1, n2, v1, v2);

    if(v1 && v2 || v1 && find(lca, n2) || v2 && find(lca, n1)){
        return lca;
    }

    return NULL;
}

int main(){
    Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 

    Node* LCA = findLCA(root, 4, 5);

    if(LCA){
        cout<<"LCA(4, 5) is: "<<LCA->data;
    }
    else{
        cout<<"Key not present";
    }

    return 0;
}