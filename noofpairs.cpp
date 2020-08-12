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

int countPairs(Node* root1, Node* root2, int x){
    if(!root1 || !root2) return 0;

    stack<Node*> s1, s2;
    Node *top1, *top2;
    int count = 0;
    while(1){
        while(root1){
            s1.push(root1);
            root1 = root1->left;
        }

        while(root2){
            s2.push(root2);
            root2 = root2->right;
        }

        if(s1.empty() || s2.empty()) break;

        top1 = s1.top();
        top2 = s2.top();

        if((top1->data + top2->data) == x){
            count++;

            s1.pop();
            s2.pop();
            root1 = top1->right;
            root2 = top2->left;
        }

        else if((top1->data + top2->data) < x){
            s1.pop();
            root1 = top1->right;
        }

        else{
            s2.pop();
            root2 = top2->left;
        }
    }
    return count;
}

int main(){
    Node* root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(7);
    root1->right->right = new Node(8);
    root1->right->left = new Node(6);
    root1->left->right = new Node(4);
    root1->left->left = new Node(2);

    Node* root2 = new Node(10);
    root2->left = new Node(6);
    root2->right = new Node(15);
    root2->right->right = new Node(18);
    root2->right->left = new Node(11);
    root2->left->right = new Node(8);
    root2->left->left = new Node(3);

    cout<<countPairs(root1, root2, 16);

    return 0;
}