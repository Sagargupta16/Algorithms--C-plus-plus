#include<iostream>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = NULL;
    }
};
Node* Insert(Node* head,int d){
    Node* newNode = new Node(d);
    if(head==NULL){
        head = newNode;
    }
    else{
        Node* temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* HeapSort(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        int smallest = temp->data;
        Node* smallestNode = temp;
        Node* curr = temp->next;
        while(curr!=NULL){
            if(curr->data<smallest){
                smallest = curr->data;
                smallestNode = curr;
            }
            curr = curr->next;
        }
        swap(temp->data,smallestNode->data);
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {8,10,3,5,1,5,4,2,1,9,7,6};
    Node* head = NULL;
    for(int i=0;i<arr.size();i++){
        head=Insert(head,arr[i]);
    }
    print(head);
    head = HeapSort(head);
    print(head);

    return 0;
}