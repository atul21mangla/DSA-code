#include<bits/stdc++.h>
using namespace std;

int longestSubstringBrute(string s){  //! Brute Force 
    int n = s.length();
    int maxLen = INT_MIN;
    for(int i=0;i<n;i++){
        unordered_map<char,int>mpp;
        int count=0;
        for(int j=i;j<n;j++){
            if(mpp.find(s[j])!=mpp.end()){
                maxLen = max(maxLen,count);
                mpp.clear();
                break;
            }
            else{
                mpp[s[j]]++;
                count += 1;
            }
        }
    }
    return maxLen;
}

int longestSubstringOptimal(string s){   //! Optimal
    int n = s.length();
        unordered_map<char,int>mpp;
        int maxLen=0;
        int count = 0;
        int left = 0;
        for(int i=0;i<n;i++){
            if(mpp.find(s[i])!=mpp.end()){
                maxLen = max(maxLen,count);
                while(mpp.count(s[i])!=0){
                    mpp[s[left]]--;
                    if(mpp[s[left]]==0)mpp.erase(s[left]);
                    left++;
                    count--;
                }
            }
            mpp[s[i]]++;
            count++;
        }
        maxLen = max(maxLen,count);
        return maxLen;
}

int main(){
    string s = "abcdecbeadf";
    // cout << longestSubstringBrute(s) << endl; 
    cout << longestSubstringOptimal(s) << endl;
    return 0;
}