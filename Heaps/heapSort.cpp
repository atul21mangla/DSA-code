#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr , int n , int idx){
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
        heapify(arr, n ,maxIdx);
    }
}
void heapSort(vector<int>& arr){   // TC - O(N + N logN)   //! SC - O(log n) due to heapify function call stack but can be optimized if we implement heapify iiteratively
    int n = arr.size();
    //! 1st step is to build max heap from array
    for(int i=n/2-1;i>=0;i--){     // TC - O(N)
        heapify(arr,n,i);
    }

    int heapSize = n;
    while(heapSize>1){          //! TC - O(n logn)       
        swap(arr[0],arr[heapSize-1]);
        heapSize--;
        heapify(arr,heapSize,0);   //! heapify on root   TC - O(log n)
    }
}

int main(){
    vector<int> arr = {2,5,3,8,1,9};
    heapSort(arr);
    for(int x:arr)cout<<x<<" ";
    cout<<endl;
    return 0;
}