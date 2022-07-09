#include<iostream>
#include<vector>
using namespace std;

void radixsort(vector<int>& arr){
    int max = arr[0];
    for(int i=1;i<arr.size();i++){
        if(arr[i]>max) max = arr[i];
    }
    for(int i=1;max/i>0;i*=10){
        vector<int>bucket[10];
        for(int j=0;j<arr.size();j++){
            int digit = (arr[j]/i)%10;
            bucket[digit].push_back(arr[j]);
        }
        int index = 0;
        for(int j=0;j<10;j++){
            for(int k=0;k<bucket[j].size();k++){
                arr[index++] = bucket[j][k];
            }
        }
    }
}//O(n);

void print(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> arr = {11,9,21,8,17,19,13,1,24,12,10};
    radixsort(arr);
    print(arr);
    return 0;
}