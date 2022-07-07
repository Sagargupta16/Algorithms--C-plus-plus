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
    Node* Insert(Node* head , int data){
        Node* newNode = new Node(data);
        if(head==NULL){
            return newNode;
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
    // Merge Sort Linked List
    Node* Merge(Node* head1 , Node* head2){
        Node* head = NULL;
        if(head1==NULL){
            return head2;
        }
        else if(head2==NULL){
            return head1;
        }
        else{
            if(head1->data<=head2->data){
                head = head1;
                head->next = Merge(head1->next , head2);
            }
            else{
                head = head2;
                head->next = Merge(head1 , head2->next);
            }
        }
        return head;
    }
    
    Node* MergeSort(Node* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        Node* slow = head;
        Node* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* head1 = head;
        Node* head2 = slow->next;
        slow->next = NULL;
        head1 = MergeSort(head1);
        head2 = MergeSort(head2);
        return Merge(head1,head2);
    }//O(nLogn)

    void print(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(){
    vector<int> a = {5,3,7,2,8,1,0,12,6,4,10,9,11};
    LinkedList l;
    Node *head = NULL;
    for(int i=0;i<a.size();i++) head=l.Insert(head,a[i]);
    head=l.MergeSort(head);
    l.print(head);

    return 0;
}