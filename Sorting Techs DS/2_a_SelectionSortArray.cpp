#include<iostream>
#include<vector>
using namespace std;

//Selection Sort
void SelectionSort(vector<int>& a){
    int n = a.size();
    for(int i=0;i<n;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min = j;
            }
        }
        swap(a[i],a[min]);
    }//O(n^2);
}

void print(vector<int>& a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> a ={3,2,9,18,4,10,84,52};
    SelectionSort(a);
    print(a);
    return 0;
}