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

int diameter(Node* root, int &ans){
    if(!root) return 0;

    int hleft = diameter(root->left, ans);
    int hright = diameter(root->right, ans);
    ans = max(ans, hleft + hright + 1);
    return (1 + max(hleft, hright));
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int ans = INT_MIN;
    int height_of_tree = diameter(root, ans); 
    
    cout<<"diameter is: "<<ans;

    return 0;
}