#include<iostream>
#include<vector>
using namespace std;

// Heap Sort Array
void Heapify(vector<int>& arr ,int n ,int i){
    int largest = i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && arr[l]>arr[largest]){
        largest = l;
    }
    if(r<n && arr[r]>arr[largest]){
        largest = r;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        Heapify(arr,n,largest);
    }
}
void HeapSort(vector<int>& arr){
    int n = arr.size();
    for(int i=n/2-1;i>=0;i--){
        Heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        Heapify(arr,i,0);
    }
}//O(nLogn)

void print(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {8,10,3,5,1,5,4,2,1,9,7,6};
    HeapSort(arr);
    print(arr);
    
    return 0;
}