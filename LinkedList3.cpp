#include <bits/stdc++.h>
#include <ctime>
using namespace std;

using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *pre;
        
        Node(int data): data(data), next(nullptr), pre(nullptr){}
};

class LinkedList{
    public:
        Node* head;
        Node* tail;

    public:
    LinkedList() : head(nullptr){}
        void insert(int data){
            Node* newNode = new Node(data);
            if(head == nullptr){
                head = newNode;
                return;
            }
            Node* current= head;
            while(current->next!=nullptr){
                current = current->next;
            }

            current->next = newNode;
        }


        void delete_divis3or5(){

            if (head == nullptr) {

                return;}

            Node* curr= head;

            int n = size();
            Node* temp = head;
            Node* temp1 = temp;

            for(int i=0; i<n; i++){
                if(temp->data %3 ==0 || temp->data %5 ==0){
                    if (temp == head){
                        head = temp->next;
                    }
                    else{
                        temp1->next = temp->next;
                    }
                    delete temp;
                    temp = temp1->next;
                }
                else{
                temp1= temp;
                temp = temp->next;}
            } 
        }
        
        void insertOrder(int data) {
        Node* newNode = new Node(data);

            if (head == nullptr || head->data >= data) {
                newNode->next = head;
                head = newNode;
                return;
            }
            Node* current = head;
            while (current->next != nullptr && current->next->data < data) {
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
        }

        int size(){
            Node* temp = head;
            int count=0;
            while(temp!=nullptr){
                temp = temp->next;
                count++;
            }
            
            return count;
        }

        void printlist(){
            Node* temp = head;
            
            cout<<"[ ";
            while(temp!=nullptr){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<"]"<<endl;
        }

        ~LinkedList(){
            clear();
        }

        private:
        void clear() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

};

int main(){
    srand(time(0));
    int arr[20];
    int arr2[10];

    for(int i=0; i<20; i++){
        arr[i] = rand() % 20;
    }
    for(int i=0; i<10; i++){
        arr2[i] = rand() % 10;
    }

    cout<<"]"<<endl;

    LinkedList list; 
    LinkedList list2;

    //1
    for(int i:arr){
        list.insert(i);
    }

    cout<<"Original: ";
    list.printlist();

    list.delete_divis3or5();
    cout<<"Updated: ";
    list.printlist();

    //2
    cout<<" Original: [";
    for(int i:arr2){
        cout<<i<<" ";
    }
    cout<<"]"<<endl;

    for(int i:arr2){
        list2.insertOrder(i);
    }
    cout<<"After insertion: ";

    list2.printlist();


    




}