#include<iostream>
#include<vector>
using namespace std;
bool flag = false;

void allOcc(int *arr,int n,int i,int target,vector<int>& ans){
    // Base case
    if(i==n){
        if(!flag)ans.push_back(-1);
        return;
    }

    // Recursive Case
    if(arr[i]==target){
        flag = true;
        ans.push_back(i);
    }
    allOcc(arr,n,i+1,target,ans);
}

int main(){
    int arr[] = {2,4,7,3,2,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 20;
    vector<int> a;
    allOcc(arr,n,0,target,a);
    cout<<"All Occurences of "<<target<<" are : ";
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    return 0;
}