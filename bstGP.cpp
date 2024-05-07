#include <bits/stdc++.h>
using namespace std;

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
    public: void preorder(){
        preorderHelper(root);
        cout<<endl;
    }
    private: void preorderHelper(Node* root){
        if(root == nullptr) return;

        cout<< root->data <<" ";
        preorderHelper(root->left);
        preorderHelper(root->right);
    }
    public: void inorder(){
        inorderHelper(root);
        cout<<endl;
    }
    private: void inorderHelper(Node* root){
        if(root == nullptr) return;

        inorderHelper(root->left);
        cout<< root->data <<" ";
        inorderHelper(root->right);
    }  
    public: void postorder(){
        postorderHelper(root);
        cout<<endl;
    }
    private: void postorderHelper(Node* root){
        if(root == nullptr) return;

        postorderHelper(root->left);
        postorderHelper(root->right);
        cout<< root->data <<" ";
    } 

        public: void divisby3or5(){
        divisby3or5_(root);
        cout<<endl;
    }
    private: void divisby3or5_(Node* root){
        if(root == nullptr) return;

        divisby3or5_(root->left);
        if(root->data %3 == 0 || root->data %5 == 0){
            cout<< root->data <<" ";}
        divisby3or5_(root->right);
    }
    public: void displayleaves(){
        printleaves(root);
        cout<<endl;
    }
    private: void printleaves(Node* root){
        if(root == nullptr) return;

        printleaves(root->left);
        if(root->left==nullptr && root->right==nullptr){
            cout<< root->data <<" ";
        }
        printleaves(root->right);
    }
    public: int height(){
        return heightHelper(root);
    }
    private: int heightHelper(Node* root){
        if(root==nullptr) return 0;

        int leftHeight = heightHelper(root->left) + 1;
        int rightHeight = heightHelper(root->right) + 1;

        return leftHeight > rightHeight
                ?leftHeight: rightHeight;
    }
    public: void sumRootnChild(){
        sumRootnChildHelper(root);
    }
    private: void sumRootnChildHelper(Node* root){
        if (root == nullptr) return;

        int left = root->left == nullptr ? 0 : root->left->data;
        int right = root->right == nullptr ? 0 : root->right->data;
        int sum = root->data + left + right;

        cout<<"Root: "<<root->data<< ",sum : "<<sum<<endl;
        sumRootnChildHelper(root->left);
        sumRootnChildHelper(root->right);
    }
    public: void sumSubtree(){
        sumHelper(root);
    }
    private: int sumHelper(Node* root){
        if(root == nullptr) return 0;
        
        int leftData=0;
        int rightData=0;
        root->left == nullptr ? leftData = 0 : leftData - root->left->data;
        root->right == nullptr ? rightData = 0 : rightData - root->right->data;
        int left = sumHelper(root->left)+ leftData;
        int right = sumHelper(root->right)+ rightData;

        int sum = left + right + root->data;
        if(root->left!=nullptr && root->right!=nullptr){
            cout<<"Root: "<<root->data<<" ,sum of subtree: "<<sum<<endl;
        }
        return sum;
    }



};


int main(){
    //1
    BST tree;
    srand(time(0));
    for(int i=0;i<30;i++){
        tree.insert(rand()%30);
    }

    //2
    cout<<"2: "<<endl;
    tree.preorder();
    tree.inorder();
    tree.postorder();

    //3
    cout<<"3: "<<endl;
    tree.divisby3or5();

    //4
    cout<<"4: "<<endl;
    tree.displayleaves();
    return 0;

    //5
    cout<<"5: "<<endl;
    cout<<"tree height = "<<tree.height()<<endl;
    
    //6
    cout<<"6: "<<endl;
    tree.sumRootnChild();

    //7
    cout<<"7: "<<endl;
    tree.sumSubtree();
    
    return 0;
}