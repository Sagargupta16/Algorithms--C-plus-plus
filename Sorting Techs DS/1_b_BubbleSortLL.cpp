#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};
class LinkedList{
public:
    Node* head;
    LinkedList(){
        this->head = NULL;
    }
    void Insert(int data){
        Node* newNode = new Node(data);
        if(this->head==NULL){
            this->head = newNode;
        }
        else{
            Node* temp = this->head;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    //Bubble Sort on Linked List Swapping data of two nodes
    void BubbleSort(){
        Node* temp = this->head;
        while(temp->next!=NULL){
            Node* temp2 = temp->next;
            while(temp2!=NULL){
                if(temp->data>temp2->data){
                    swap(temp->data,temp2->data);
                }
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
    }//O(n^2)

    void print(){
        Node* temp = this->head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};


int main(){
    vector<int> a={3,2,9,18,4,10,84,52};
    LinkedList l;
    for(int i=0;i<a.size();i++) l.Insert(a[i]);
    l.BubbleSort();
    l.print();
    return 0;
}