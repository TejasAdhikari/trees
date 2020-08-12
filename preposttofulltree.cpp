#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = this->right=NULL;
    }
};

Node* buildTree(int pre[], int post[], int l, int h, int len){
    static int preIndex = 0;
    if(preIndex >= len || l>h) return NULL;

    Node* root = new Node(pre[preIndex++]);

    if(l == h) return root; 

    int i;
    for(i = l; i<=h; ++i){
        if(pre[preIndex] == post[i]) break;
    }

    if(i <= h){
        root->left = buildTree(pre, post, l, i, len);
        root->right = buildTree(pre, post, i+1, h-1, len);
    }

    return root;
}

void inorder(Node* root){
    if(!root) return;

    inorder(root->left);

    cout<<root->data<<" ";

    inorder(root->right);
}
//reverse of pre order traversal of mirror full tree is 
//the post order traversal of original full tree
int main(){
    int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};

    int len = sizeof(pre) / sizeof(pre[0]);
    Node* root = buildTree(pre, post, 0, len-1 , len);

    cout<<"inorder traversal of the constructed tree is: ";
    inorder(root);

    return 0;
}