#include<bits/stdc++.h>
using namespace std;

int solveBrute(int arr[][100] , int n){
    int know_me[n];
    int i_know[n];
    fill(know_me, know_me + n, 0);  // Initialize arrays to 0
    fill(i_know, i_know + n, 0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==1){
                know_me[j]++;
                i_know[i]++;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(know_me[i]==n-1 and i_know[i]==0)return i;
    }
    return -1;
}

int solveOptimal(int arr[][100] , int n){
    int top = 0;
    int down = n-1;
    while(top<down){
        if(arr[top][down]==1)top++;    // top can't be my celebrity 
        else if(arr[down][top]==1)down--;  // down can't be my celebrity
        else{
            top++;
            down--;
        }
    }
    if(top>down){
        return -1;
    }
    else{   // top==down at this moment
        for(int i=0;i<n;i++){
            if(i==top)continue;
            if(!(arr[top][i]==0 and arr[i][top]==1))return -1;
        }
        return top;
    }
}

int main(){
    int n;
    cin>>n;
    int arr[100][100];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    } 
    // cout<<solveBrute(arr,n);
    cout<<solveOptimal(arr,n);
    return 0;
}