#include<iostream>
#include<vector>
using namespace std;

//Insertion Sort
void InsertionSort(vector<int>& a){
    int n = a.size();
    for(int i=1;i<n;i++){
        int key = a[i];
        int j = i-1;
        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = key;
    }
}//O(n^2);

void print (vector<int>& a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> a={5,12,28,3,23,12,45,67,34,56,75,42};
    InsertionSort(a);
    print(a);
    return 0;
}