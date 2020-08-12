#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    char data;
    Node* left;
    Node* right;
    Node(char data){
        this->data = data;
        this->left = this->right = NULL;
    }
};

Node* buildTree(char in[], char pre[], int inStart, int inEnd, unordered_map<char, int> &mp){
    static int preIndex = 0;

    if(inStart > inEnd) return NULL;

    char current = pre[preIndex++];
    Node* root = new Node(current);

    if(inStart == inEnd) return root;

    int inIndex = mp[current];

    root->left = buildTree(in, pre, inStart, inIndex-1, mp);
    root->right = buildTree(in, pre, inIndex+1, inEnd, mp);    

    return root;
}

void inorder(Node* root){
    if(!root) return;

    inorder(root->left);

    cout<<root->data<<" ";

    inorder(root->right);
}

int main(){
    char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
    char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};

    int len = sizeof(in) / sizeof(in[0]);

    cout<<sizeof(in)<<endl;

    unordered_map<char, int> mp;
    for (int i = 0; i < len; i++){
        mp[in[i]] = i;
    }
    
    Node* root = buildTree(in, pre, 0, len-1, mp);
    cout<<"inorder traversal of the constructed tree: ";
    inorder(root);  
}