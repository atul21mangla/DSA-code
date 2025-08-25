#include<bits/stdc++.h>
using namespace std;

void updateArray(vector<int>& arr , vector<vector<int>>& updates , int n){
    int len = updates.size();
    for(int i=0;i<len;i++){
        int l = updates[i][0];
        int r = updates[i][1];
        int x = updates[i][2];

        arr[l] += x;
        if(r+1<n){
            arr[r+1] -= x;
        }  
    }

    for(int i=1;i<n;i++){
        arr[i] += arr[i-1];
    }
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n,0);
    vector<vector<int>>updates = {{1,3,2},{2,4,3},{0,2,-2}};
    updateArray(arr,updates,n);

    for(int x:arr){
        cout << x << " ";
    }
    return 0;
}

//? You are given an integer length and an array updates where updates[i] = [startIdxi, endIdxi, inci].

//? You have an array arr of length length with all zeros, and you have some operation to apply on arr. In the ith operation, you should increment all the elements arr[startIdxi], arr[startIdxi + 1], ..., arr[endIdxi] by inci.

//? Return arr after applying all the updates.

// Input: updates = length = 5 , [[1,3,2],[2,4,3],[0,2,-2]]
// Output: [-2,0,3,5,3]

// Input: updates = length = 10 , [[2,4,6],[5,6,8],[1,9,-4]]
// Output: [0,-4,2,2,2,4,4,-4,-4,-4]