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

void printPathUtil(Node* root, int path[], int pathlen){
    if(root == NULL) return;
    path[pathlen] = root->data;
    pathlen++;
    if(root->left == NULL && root->right == NULL){
        for(int i = 0; i <= pathlen; i++){
            cout<<path[i]<<" ";
        }
        cout<<endl;
    }
    else{
        printPathUtil(root->left, path, pathlen);
        printPathUtil(root->right, path, pathlen);
    }
}

bool sumPathUtil(Node* root, int sum){
    if(!root) return (sum == 0);

    bool ans = false;
    sum -= root->data;
    if(sum == 0 && !root->left && !root->right){
        return true;
    }

    if(root->left) {
        ans = ans || sumPathUtil(root->left, sum);
    }
    if(root->right){
        ans = ans || sumPathUtil(root->right, sum);
    }

    return ans;
}

void printPaths(Node* root){
    int path[1000];
    printPathUtil(root, path, 0);
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<"root to leaf paths: ";
    printPaths(root);

    int sum;
    cout<<"enter a number to check: ";
    cin>>sum;
    cout<<sumPathUtil(root, sum);
    
    return 0;
}