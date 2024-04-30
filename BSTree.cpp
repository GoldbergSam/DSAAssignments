#include <iostream>

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data): data(data), left(nullptr), right(nullptr){}
};

class BST{
    Node* root;
    public:
    BST():root(nullptr){};

    public: void insert(int data){
        Node* newNode = new Node(data);
        root = insertHelper(root, newNode);
    }
    private: Node* insertHelper(Node* root, Node* newNode){
        if(root==nullptr)return newNode;

        if(newNode->data < root->data){
            root->left = insertHelper(root->left, newNode);
        }
        else{
            root->right = insertHelper(root->right, newNode);
        }
        return root;
    }

    public: void tprint(){
        printHelper(root);
    }
    private: void printHelper(Node* root){
        if(root==nullptr) return;
        printHelper(root->left);
        std::cout<<root->data<<" ";
        printHelper(root->right);
    }

};

int main(){
    BST tree;
    int arr[] = {5,6,8,200,4,6,7,63,563,35,3};

    for(int i: arr){
        tree.insert(i);
    }

    tree.tprint();
}
