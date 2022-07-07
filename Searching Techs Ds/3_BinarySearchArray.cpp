// Only on Sorted Array
// Binary Search cant be used on unsorted array and on Linked List
#include<iostream>
#include<vector>
using namespace std;

//BinarySearch on Array
bool BinarySearch(vector<int>& a,int key){
    int l=0,h=a.size()-1,m;
    while(l<=h){
        m=(l+h)/2;
        if(key==a[m]) return true;
        if(key<a[m]) h = m-1;
        else l=m+1;
    }
    return false;
}//O(Log(n))

int main(){
    vector<int> a={3,6,9,10,92,103,208,408,999};
    int key = 7;

    if(BinarySearch(a,key)){
        cout<<"Key Found"<<endl;
    }
    else{
        cout<<"Key Not Found "<<endl;
    }

    return 0;
}