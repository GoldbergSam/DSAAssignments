#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* pre;
    public: Node(int data): data(data), next(nullptr), pre(nullptr){};
};

class DoublyLinkedList{
    private:
    Node* head;
    Node* tail;
    public: DoublyLinkedList():head(nullptr), tail(nullptr){};
//1
    void printls(){
        cout<<"[ ";
        Node* temp=head;
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<"]";
    }
    void reversels(){
        cout<<"[ ";
        Node* temp=tail;
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->pre;
        }
        cout<<"]"<<endl;
    }
//2
    void stack(int data){
        Node* newNode = new Node(data);
        if(head == nullptr){
            head = newNode;
            tail = head;}

        else{
            tail->next = newNode;
            newNode->pre = tail;
            tail = newNode;
            }
    }
    void enqueue(int data){
        Node* newNode = new Node(data);
        if(head == nullptr){
            head = newNode;
            tail = head;}
        else{
            head->pre = newNode;
            newNode->next = head;
            head = newNode;
        };   
    }

    int size(){
        Node* temp = head;
        int count=0;
        while(temp!=nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void insertp(int data, int pos){
        if(pos>size()) return;
        Node* newNode = new Node(data);
        
        if(pos==size()){
            newNode->pre = tail;
            tail->next = newNode;
            tail = newNode;
            
        }
        else if(pos==0){
            newNode->next = head;
            head->pre = newNode;
            head = newNode;
            
        }
        else{
            Node* temp = head;
            for(int i=0; i<pos;i++ ){
                temp = temp->next;
            } 
            newNode->next = temp;
            newNode->pre = temp->pre;
            temp->pre->next = newNode;
            temp->pre = newNode;
            }
        }
//3
    void delfirst(){
        if(head ==nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void dellast(){
        if(tail== nullptr) return;
        Node*temp = tail;
        tail = tail->pre;
        delete temp;
    }

    void delpos(int pos){
        if(pos>=size())return;

        if(pos==0)delfirst();
        else if(pos==size()-1)dellast();
        else{
            Node* temp = head;
            for(int i=0;i<pos;i++){
                temp = temp->next;
            }
            temp->pre->next = temp->next;
            temp->next->pre = temp->pre;
            delete temp;
        }
    }

};
class SingleLinkedList{
    private:
    Node* head;

    public: SingleLinkedList():head(nullptr){};
//1
    void printls(){
        cout<<"[ ";
        Node* temp=head;
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<" ]";
    }
    void reversels(){
        cout<<"[ ";
        reverseHelper(head);
        cout<<"]";
    }
    void reverseHelper(Node* node){
        if(node== nullptr) return;
        reverseHelper(node->next);
        cout<<node->data<<" ";
    }
//2
    void sstack(int data){
        Node* newNode = new Node(data);
        if(head == nullptr){
            head = newNode;}

        else{
            Node* temp = head;
            while(temp->next!=nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void enqueue(int data){
        Node* newNode = new Node(data);
        if(head == nullptr){
            head = newNode;
            }
        else{
            newNode->next = head;
            head = newNode;
        };   
    }

    int size(){
        Node* temp = head;
        int count=0;
        while(temp!=nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void insertp(int data, int pos){
        if(pos>size()) return;
        Node* newNode = new Node(data);
        
        if(pos==size()){
            sstack(data);
        }
        else if(pos==0){
            enqueue(data);
        }
        else{
            Node* temp = head;
            for(int i=0; i<pos-1;i++ ){
                temp = temp->next;
            } 
            newNode->next = temp->next;
            temp->next = newNode;
            }
        }
//3
    void delfirst(){
        if(head ==nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void dellast(){
        Node *temp = head;
        Node *temp2 = temp;
        while(temp->next!=nullptr){
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = nullptr;
        delete temp;
    }

    void delpos(int pos){
        if(pos>=size())return;

        if(pos==0)delfirst();
        else if(pos==size()-1)dellast();
        else{
            Node* temp = head;
            for(int i=0;i<pos-1;i++){
                temp = temp->next;
            }
            Node* dtemp = temp->next;
            temp->next = temp->next->next;
            delete dtemp;
        }
    }
    

};


int main(){
    SingleLinkedList listSingle;
    DoublyLinkedList listDouble;

    int arrS[] = {3,6,9,10};
    int arrD[]= {2,4,7,9,11};

    for(int i:arrS){
        listSingle.sstack(i);
    }
    for(int i:arrD){
        listDouble.stack(i);
    }

    //1
    cout<<"Traverse: left->right ,Single, Double vice versa Respectively:  "<<endl;
    listSingle.printls();
    cout<<endl;

    listSingle.reversels();
    cout<<endl;

    listDouble.printls();
    cout<<endl;

    listDouble.reversels();
    cout<<endl;
    //2
        cout<<"Insert: front, pos, last (Single, Double) Respectively:  "<<endl;
    listSingle.enqueue(1); listSingle.printls();
    cout<<endl;

    listSingle.insertp(2,2); listSingle.printls();
    cout<<endl;

    listSingle.sstack(3); listSingle.printls();
    cout<<endl;
    cout<<"Doubly: "<<endl;

    listDouble.enqueue(1); listDouble.printls();
    cout<<endl;

    listDouble.insertp(2,2); listDouble.printls();
    cout<<endl;

    listDouble.stack(3); listDouble.printls();
    cout<<endl;
    //3
    cout<<"Delete: front, pos, last (Single, Double) Respectively:  "<<endl;
    listSingle.delfirst(); listSingle.printls();
    cout<<endl;

    listSingle.delpos(2); listSingle.printls();
    cout<<endl;

    listSingle.dellast(); listSingle.printls();
    cout<<endl;
    cout<<"Doubly: "<<endl;

    listDouble.delfirst(); listDouble.printls();
    cout<<endl;

    listDouble.delpos(2); listDouble.printls();
    cout<<endl;

    listDouble.dellast(); listDouble.printls();
    cout<<endl;

    return 0;
}