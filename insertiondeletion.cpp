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

void display(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* current = q.front();
        cout<<current->data<<" ";
        q.pop();
        if(current->left) q.push(current->left);
        if(current->right) q.push(current->right);
    }
}

void insertion(Node* root, int insert){
    if(root == NULL) root->data = insert;

    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        if(current->left){
            q.push(current->left);
        }
        else{
            current->left = new Node(insert);
            return;
        }
        if(current->right){
            q.push(current->right);
        }
        else{
            current->right = new Node(insert);
            return;
        }
    }
}

void deleteNode(Node* root, Node* key_node_delete){
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* current = q.front();
        q.pop();
        if(current == key_node_delete){
            current = NULL;
            delete(current);
            return;
        }

        if(current->right){
            if(current->right == key_node_delete){
                current -> right = NULL;
                delete(current->right);
                return;
            }
            else{
                q.push(current->right);
            }
        }

        if(current->left){
            if(current->left == key_node_delete){
                current->left = NULL;
                delete(current->left);
                return;
            }
            else{
                q.push(current->left);
            }
        }
    }
}

void deletion(Node* root, int key){
    if(root == NULL) return;

    Node* current , * key_node = NULL;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        current = q.front();
        q.pop();
        if(current->data == key) key_node = current;
        if(current->left) q.push(current->left);
        if(current->right) q.push(current->right);
    }

    key_node->data = current->data;
    deleteNode(root, current);
    // current = NULL;
    // delete(current);
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int insert;
    cout<<"number to insert: ";
    cin>>insert;
    insertion(root, insert);
    cout<<"done"<<endl;
    display(root);

    int key;
    cout<<"\n number to delete: ";
    cin>>key;
    deletion(root, key);
    cout<<"done"<<endl;
    display(root);

}