#include<iostream>
#include<vector>
using namespace std;

// Merge Sort Array
void Merge(vector<int>& arr ,int l ,int m ,int r){
    int i , j , k;
    int n1 = m-l+1;
    int n2 = r-m;
    vector<int> L(n1);
    vector<int> R(n2);
    for(i=0;i<n1;i++){
        L[i] = arr[l+i];
    }
    for(j=0;j<n2;j++){
        R[j] = arr[m+1+j];
    }
    i = 0;
    j = 0;
    k = l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(vector<int>& arr ,int start ,int end){
    if(start<end){
        int mid=(start+end)/2;
        MergeSort(arr,start,mid);
        MergeSort(arr,mid+1,end);
        Merge(arr,start,mid,end);
    }
}//O(nLogn)

void print(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> a = {4,3,1,5,8,3,2,1,9,7,6};
    MergeSort(a,0,a.size()-1);
    print(a);
    return 0;
}