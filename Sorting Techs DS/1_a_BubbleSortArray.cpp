#include<iostream>
#include<vector>
using namespace std;

//Bubble Sort
void BubbleSort(vector<int>& a){
    int n = a.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
}//O(n^2);

void print(vector<int>& a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> a={3,2,9,18,4,10,84,52};
    BubbleSort(a);
    print(a);
    return 0;
}