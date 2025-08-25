//  https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=leaders-in-an-array

#include<bits/stdc++.h>
using namespace std;

vector<int> leaders(vector<int>& arr) {
    // Code here
    stack<int>st;
    int n = arr.size();
    st.push(arr[n-1]);
    for(int i=n-2;i>=0;i--){
        if(arr[i] >= st.top()) st.push(arr[i]);
    }
    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

int main(){
    // vector<int>arr = {16, 17, 4, 3, 5, 2};     //! output = {17,5,2}
     vector<int>arr = {65,65,1};           //? output = {65,65,1}

    vector<int>ans = leaders(arr);
    for(int x:ans){
        cout << x << " ";
    }
    return 0;
}