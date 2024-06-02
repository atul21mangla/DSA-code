#include<bits/stdc++.h>
using namespace std;

void printarr(vector<int>& arr){
    for(auto it:arr){
        cout<<it<<" ";
    }
    cout<<endl;
}

void moveNegativeToStart_1(vector<int>& arr){
    int n = arr.size();
    int i=-1;
    int j=0;
    while(j<n){
        if(arr[j] < 0){
            swap(arr[j++] , arr[++i]);
        }
        else
        j++;
    }
}

//! Dutch National Flag Approach
void moveNegativeToStart_2(vector<int>& arr){
    int n = arr.size();
    int i = 0;
    int j = n-1;
    while(i<=j){
        if(arr[i] < 0)i++;
        else if(arr[i] > 0){
            swap(arr[i] , arr[j--]);
        }
    }
}

int main(){
    int n;
    vector<int>arr;
    cout<<"Enter size of array : "<<endl;
    cin>>n;

    for(int i=0;i<n;i++){
        int j;
        cout<<"Enter "<<i+1<<" element for array :";
        cin>>j;
        arr.push_back(j);
    }
    cout<<"Before array ------------------"<<endl;
    printarr(arr);
    // moveNegativeToStart_1(arr);
    moveNegativeToStart_2(arr);
    cout<<"After array ------------------"<<endl;
    printarr(arr);

    return 0;
}