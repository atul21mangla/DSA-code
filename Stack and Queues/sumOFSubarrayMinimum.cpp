#include<bits/stdc++.h>
using namespace std;

vector<int> nextSmallerIndex(vector<int>v){
    int n = v.size();
    vector<int>ans;
    stack<int>st;  // storing index at stack
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && v[st.top()]>= v[i]){
            st.pop();
        }
        if(st.empty()){
            ans.push_back(n);
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
vector<int> prevSmallerIndex(vector<int>v){
    int n = v.size();
    vector<int>ans;
    stack<int>st;  // storing index at stack
    for(int i=0;i<n;i++){
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
    return ans;
}

int sumSubarrayMinimumBrute(vector<int>v){
    int n = v.size();
    int sum = 0;
    int mod = 1e9+7;
    for(int i=0;i<n;i++){
        int mini = v[i];
        for(int j=i;j<n;j++){
            mini = min(mini , v[j]);
            sum = (sum + mini)%mod;
        }
    }
    return sum;
}

int sumSubarrayMinimumOptimal(vector<int>v){
    int mod = 1e9+7;
    int n = v.size();
    vector<int>leftIndex = prevSmallerIndex(v);
    vector<int>rightIndex = nextSmallerIndex(v);
    int sum = 0;
    for(int i=0;i<n;i++){
        int l = i - leftIndex[i];
        int r = rightIndex[i] - i;
        long long contri_i = 1ll * l * r * v[i];  // ensure multiplication is done in long long
        sum = (sum + contri_i) % mod;
    }
    return sum;
}


int main(){
    vector<int>v;
    int n;
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    // cout << sumSubarrayMinimumBrute(v) << endl;
    cout << sumSubarrayMinimumOptimal(v) << endl;
    return 0;
}