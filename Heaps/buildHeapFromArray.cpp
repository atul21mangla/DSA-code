#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr , int idx){
    int n = arr.size();
    int maxIdx = idx;
    int leftChild = 2*idx + 1;
    int rightChild = 2*idx + 2;
    if(leftChild<n && arr[leftChild] > arr[maxIdx]){
        maxIdx = leftChild;
    }
    if(rightChild<n && arr[rightChild] > arr[maxIdx]){
        maxIdx = rightChild;
    }

    if(maxIdx!=idx)
    {
        swap(arr[maxIdx],arr[idx]);
        heapify(arr,maxIdx);
    }
}

void buildHeap(vector<int>& arr){
    int n = arr.size();
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,i);
    }
}

int main(){
    vector<int>arr = {2,5,3,8,1,9}; 
    for(int x:arr)cout<<x<<" ";
    cout<<endl;
    buildHeap(arr);
    for(int x:arr)cout<<x<<" ";
    cout<<endl;
    return 0;
}