#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void BucketSort(vector<int>& arr,int BucketSize){
    int n = arr.size();
    int max = arr[0];
    int min = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max)
            max = arr[i];
        if(arr[i]<min)
            min = arr[i];
    }
    int bucketSize = (max-min)/BucketSize+1;
    vector<vector<int>> bucket(bucketSize);
    for(int i=0;i<n;i++){
        int j = (arr[i]-min)/bucketSize;
        bucket[j].push_back(arr[i]);
    }
    for(int i=0;i<bucketSize;i++){
        sort(bucket[i].begin(),bucket[i].end());
    }
    int index = 0;
    for(int i=0;i<bucketSize;i++){
        for(int j=0;j<bucket[i].size();j++){
            arr[index++] = bucket[i][j];
        }
    }

}//O(n^2) worst case O(n+k) Average case


void print(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> arr = {11,9,21,8,17,19,13,1,24,12};
    BucketSort(arr,3);
    print(arr);
    return 0;
}