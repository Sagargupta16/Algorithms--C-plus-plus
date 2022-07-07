#include<iostream>
#include<vector>
using namespace std;

// Linear Search
bool LinearSearch(vector<int>& a,int key){
    for(int i=0;i<a.size();i++){
        if(a[i]==key){
            return true;
        }
    }
    return false;
}//O(n)

int main(){
    vector<int> a ={3,2,9,18,4,10,84,52};
    int key = 10;
    if(LinearSearch(a,key)){
        cout<<"Key Found"<<endl;
    }
    else{
        cout<<"Key Not Found "<<endl;
    }
    return 0;
}