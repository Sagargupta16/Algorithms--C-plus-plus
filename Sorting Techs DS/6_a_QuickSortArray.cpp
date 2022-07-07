#include<iostream>
#include<vector>
using namespace std;


// Quick Sort Array
int Partition(vector<int>& arr ,int start ,int end){
    int pivot = arr[end];
    int i = start-1;
    for(int j=start;j<end;j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[end]);
    return i+1;
}
void QuickSort(vector<int>& arr, int start, int end){
    if (start < end){
        int pivot = Partition(arr, start, end);
        QuickSort(arr, start, pivot - 1);
        QuickSort(arr, pivot + 1, end);
    }
}//O(n^2) Worst Case O(nLogn) Average Case


void print(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {8,10,3,5,1,5,4,2,1,9,7,6};
    QuickSort(arr,0,arr.size()-1);
    print(arr);
    
    return 0;
}