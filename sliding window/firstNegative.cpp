#include<bits/stdc++.h>
using namespace std;

vector<int> FirstNegativeInteger(int* arr , int n , int k){   // Brute force
    vector<int>ans;                                           //! tc - O(n^2)
    for(int i=0;i<=n-k;i++){
        bool flag = false;
        for(int j=i;j<=i+k;j++){
            if(arr[j]<0){
                ans.push_back(arr[j]);
                flag = true;
                break;
            }
        }
        if(!flag){
            ans.push_back(0);
        }
    }
    return ans;
}

vector<int> FirstNegative(int* arr , int n , int k){    // Optimal Approach - Sliding Window 
    int i=0,j=0;                                        //!  TC and SC - O(N)
    queue<int>q;
    vector<int>ans;
    while(j<n){
        if(arr[j]<0){
            q.push(arr[j]);
        }
        
        if(j-i+1 < k){
            j++;
        }
        else{
            if(!q.empty()){
                ans.push_back(q.front());
                if(arr[i]<0)q.pop();
            }
            else
            ans.push_back(0);
            
            i++;
            j++;
        }
    }
    return ans;
}

int main(){
    int arr[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    // vector<int>ans = FirstNegativeInteger(arr, n, k);
    vector<int>ans = FirstNegative(arr, n, k);
    for(int a:ans){
        cout<<a<<" ";
    }cout<<endl;
    return 0;
}