#include<iostream>
#include<vector>
using namespace std;

void countSort(vector<int>& arr){
    int n = arr.size();
    int max = arr[0];
    int min = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max)
            max = arr[i];
        if(arr[i]<min)
            min = arr[i];
    }
    int range = max-min+1;
    vector<int> count(range);
    vector<int> output(n);
    for(int i=0;i<n;i++){
        count[arr[i]-min]++;
    }
    for(int i=1;i<range;i++){
        count[i] += count[i-1];
    }
    for(int i=n-1;i>=0;i--){
        output[count[arr[i]-min]-1] = arr[i];
        count[arr[i]-min]--;
    }
    for(int i=0;i<n;i++){
        arr[i] = output[i];
    }
}// O(n+k) worst case O(n+k) Average case

void print(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> arr = {11,9,21,8,17,19,13,1,24,12,10};
    countSort(arr);
    print(arr);
    return 0;
}