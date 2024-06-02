#include <bits/stdc++.h>
using namespace std;

void printArray(vector<vector<int>> &arr){
    int m = arr.size();
    int n = arr[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
//! Row Sum 
void rowSum(vector<vector<int>> &arr){
    int m = arr.size();
    int n = arr[0].size();
    for(int i=0;i<m;i++){
        int sum = 0;
        for(int j=0;j<n;j++){
            sum += arr[i][j];
        }
        cout<<"Sum of "<<i+1<<" row : "<<sum<<endl;
    }
}
//!  rev diagonal sum 
void diagSum(vector<vector<int>> &arr){
    int m = arr.size();
    int n = arr[0].size();
    int sum = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i+j == m-1)
            sum += arr[i][j];
        }
    }
    cout<<"Diagonal sum :"<<sum<<endl;
}

int main() {
    vector<vector<int>>arr(3 , vector<int>(3 , 0));
    int m = arr.size();
    int n = arr[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    printArray(arr);
    rowSum(arr);
    // colSum(arr);
    diagSum(arr);
    
    return 0;
}