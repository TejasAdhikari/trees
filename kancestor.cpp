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
 
bool kancestor(Node* root, int key, vector<int>& ka){
    if(!root) return false;

    ka.push_back(root->data);

    if(root->data == key) return true;

    if(kancestor(root->left, key, ka) || kancestor(root->right, key, ka))
        return true;
    
    ka.pop_back();
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

    vector<int> ka;
    kancestor(root, 4, ka);

    int k = 1;
    if(k > ka.size() - 1 || k<0){
        cout<<"-1";
    }
    else{
        cout<<ka[ka.size() - 1 - k];
    }
}