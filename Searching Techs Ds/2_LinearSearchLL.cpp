#include<iostream>
#include<vector>

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

    // Linear Search on Linked List
    bool LinearSearch(int key){
        Node* temp = this->head;
        while(temp!=NULL){
            if(temp->data==key){
                return true;
            }
            temp = temp->next;
        }
        return false;
    }//O(n);
};


using namespace std;
int main(){
    vector<int> a={3,2,9,18,4,10,84,52};
    LinkedList l;
    for(int i=0;i<a.size();i++) l.Insert(a[i]);

    int key = 12;
    if(l.LinearSearch(key)){
        cout<<"Key Found"<<endl;
    }
    else{
        cout<<"Key Not Found "<<endl;
    }
    return 0;
}