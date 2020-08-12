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

Node* findLCA(Node* root, int n1, int n2){
    if(!root) return root;

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* l_lca = findLCA(root->left, n1, n2);
    Node* r_lca = findLCA(root->right, n1, n2);

    if(l_lca && r_lca){
        return root;
    }

    return (l_lca) ? l_lca : r_lca;
}

int findLevel(Node* lca, int k, int level){
    if(!lca) return -1;

    if(lca->data == k) return level;

    int left = findLevel(lca->left, k, level+1);
    if(left == -1){
        return findLevel(lca->right, k, level+1);
    }
    return left;
}

int findDistance(Node* root, int n1, int n2){

    Node* lca = findLCA(root, n1, n2);

    int d1 = findLevel(lca, n1, 0);
    int d2 = findLevel(lca, n2, 0);

    return d1 + d2;
}

int main(){
    Node* root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
    root->right->left = new Node(6); 
    root->right->right = new Node(7); 

    int ans = findDistance(root, 4, 6);
    cout<<"distance between the two nodes is: "<<ans;
    return 0;
}