#include<iostream>
#include<stack>
#include<vector>
#include<limits.h>
using namespace std;

vector<int> nextSmallerElement(vector<int>v){
    int n = v.size();
    vector<int>ans(n);
    stack<pair<int,int>>s;
    for(int i=n-1;i>=0;i--){
        int ele = v[i];
        while(!s.empty() && s.top().first>ele){
            s.pop();
        }
        if(s.empty()){
            ans[i]=-1;
        }
        else{
            ans[i] = s.top().second;
        }
        s.push({ele,i});
    }
    for(auto a:ans){
        cout<<a<<" ";
    }
    cout<<endl;
    return ans;
}

vector<int> prevSmallerElement(vector<int>v){
    int n = v.size();
    vector<int>ans(n);
    stack<pair<int,int>>s;
    for(int i=0;i<n;i++){
        int ele = v[i];
        while(!s.empty() && s.top().first>ele){
            s.pop();
        }
        if(s.empty()){
            ans[i]=-1;
        }
        else{
            ans[i] = s.top().second;
        }
        s.push({ele,i});
    }
    for(auto a:ans){
        cout<<a<<" ";
    }
    cout<<endl;
    return ans;
}

int maxArea(vector<int>v){
    int n = v.size();
    vector<int>nextSmaller = nextSmallerElement(v);
    vector<int>prevSmaller = prevSmallerElement(v);
    int maxArea = INT_MIN;
    for(int i=0;i<n;i++){
        if(nextSmaller[i]==-1)nextSmaller[i]=n;
        int h = v[i]; // height 
        int w = nextSmaller[i]-prevSmaller[i]-1;
        maxArea = max(maxArea,h*w);
    }
    return maxArea;
}

int main(){
    vector<int>v = {6,2,5,4,5,1,6};
    cout<<maxArea(v);
}