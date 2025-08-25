
// https://leetcode.com/problems/minimum-window-substring/description/

#include<bits/stdc++.h>
using namespace std;

bool checkMap(unordered_map<char,int>mpp){
    for(auto it:mpp){
        if(it.second>0)return false;
    }
    return true;
}

string bruteFun(string s , string t){
    unordered_map<char,int>count;
    int m = s.length();
    int n = t.length();
    string ans = "";

    for(auto x:t)count[x]++;   // storing frequency in map 
    int minSize = INT_MAX;
    for(int i=0;i<m;i++){
        unordered_map<char,int>mpp = count;
        for(int j=i;j<m;j++){
            if(mpp.find(s[j])!=mpp.end()){
                mpp[s[j]]--;
            }
            if(checkMap(mpp)){
                if(minSize > j-i+1){
                    minSize = j-i+1;
                    ans = s.substr(i,minSize);
                }
                break;
            }
        }
    }
    return ans;
}

string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();

        unordered_map<char,int>mpp;
        for(auto x:t)mpp[x]++;
        int requiredCount = n;

        if(n>m)return "";
        int i=0,j=0,start=0,minWindowSize = INT_MAX;
        while(j<m){
            char ch = s[j];
            if(mpp[ch] > 0)requiredCount--;
            mpp[ch]--;

            while(requiredCount==0){
                if(minWindowSize > j-i+1){
                    minWindowSize = j-i+1;
                    start = i;
                }
                mpp[s[i]]++;
                if(mpp[s[i]]>0)requiredCount++;
                i++;
            }
            j++;
        }
        return minWindowSize==INT_MAX ? "" : s.substr(start,minWindowSize);
    }

int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";
    // cout<<bruteFun(s,t);
    cout << minWindow(s,t);
    return 0;
}