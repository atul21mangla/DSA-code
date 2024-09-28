#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerVal(vector<int>v){
    int n = v.size();
    vector<int>ans;
    stack<int>st;
    st.push(-1);
    for(int i=n-1;i>=0;i--){
        while(st.top()!=-1 && st.top()>= v[i]){
            st.pop();
        }
        if(st.top()==-1){
            ans.push_back(-1);
            st.push(v[i]);
        }
        else{
            ans.push_back(st.top());
            st.push(v[i]);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

vector<int> nextSmallerIndex(vector<int>v){
    int n = v.size();
    vector<int>ans;
    stack<int>st;  // storing index at stack
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && v[st.top()]>= v[i]){
            st.pop();
        }
        if(st.empty()){
            ans.push_back(-1);
            st.push(i);
        }
        else{
            ans.push_back(st.top());
            st.push(i);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    vector<int>v;
    int n;
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i];                 // v -> [1,3,4,2]
    }
    vector<int>ans = nextSmallerVal(v);
    vector<int>ansIdx = nextSmallerIndex(v);
    
    for(auto x:ans){
        cout<<x<<" ";
    }
    cout<<endl;
    for(auto x:ansIdx){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}